
#include "asset.h"


namespace engine2d {

class AssetManager {
public:
  static AssetManager& get() {
    static AssetManager s_manager;
    return s_manager;
  }

  Resource& resource() { return res_; }

private:
  Resource res_;

  AssetManager() = default;
};


const u_int getUniqueID() {
  static u_int id = 0;
  return id++;
}

Resource& asset() { return AssetManager::get().resource(); }

void assetManagerSetup() { AssetManager::get(); }
void assetRelease() { asset().clear().all(); }

}  // end engine2d
