
#pragma once
#include "../engine2d.hpp"
#include <map>


namespace engine2d {

extern const u_int getUniqueID();

class Resource {
  class AssetBase {
  protected:
    AssetBase(Resource& res) : res_(res) {}
    Resource& res_;
  };

  class AssetAppend : protected AssetBase {
  public:
    AssetAppend(Resource& res) : AssetBase(res) {}

    // TIPS: 登録に使った ID を返す
    const u_int texture(const std::string& path) {
      u_int id = getUniqueID();
      res_.texture_.emplace(std::make_pair(id, Texture(path)));
      return id;
    }

    // TIPS: 登録に使った ID を返す
    const u_int media(const std::string& path) {
      u_int id = getUniqueID();
      res_.media_.emplace(std::make_pair(id, Media(path)));
      return id;
    }
  };

  class AssetRemove : protected AssetBase {
  public:
    AssetRemove(Resource& res) : AssetBase(res) {}

    void texture(const u_int id) {
      auto itr = res_.texture_.find(id);
      if (itr != res_.texture_.end()) res_.texture_.erase(itr);
    }

    void media(const u_int id) {
      auto itr = res_.media_.find(id);
      if (itr != res_.media_.end()) res_.media_.erase(itr);
    }
  };

  class AssetDelete : protected AssetBase {
  public:
    AssetDelete(Resource& res) : AssetBase(res) {}
    void texture() { res_.texture_.clear(); }
    void media() { res_.media_.clear(); }
    void all() { texture(); media(); }
  };

  class AssetFinder : protected AssetBase {
  public:
    AssetFinder(Resource& res) : AssetBase(res) {}

    Texture* texture(const u_int id) {
      auto itr = res_.texture_.find(id);
      return (itr != res_.texture_.end()) ? &itr->second : nullptr;
    }

    Media* media(const u_int id) {
      auto itr = res_.media_.find(id);
      return (itr != res_.media_.end()) ? &itr->second : nullptr;
    }
  };

public:
  AssetAppend& append() { return append_; }
  AssetRemove& remove() { return remove_; }
  AssetDelete& clear() { return delete_; }
  AssetFinder& find() { return finder_; }

private:
  std::map<u_int, Texture> texture_;
  std::map<u_int, Media>   media_;

  AssetAppend append_;
  AssetRemove remove_;
  AssetDelete delete_;
  AssetFinder finder_;

  Resource() :
    append_(*this), remove_(*this),
    delete_(*this), finder_(*this) {}

  friend class AssetManager;
};

extern Resource& asset();

}  // end engine2d
