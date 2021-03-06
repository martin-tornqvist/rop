#include "f_container.h"
#include "entity.h"
#include <algorithm>
#include "game.h"

bool Container::addItem(Entity &a){
  if(size > 0 && inv.size() >= size){
    return false;
  }
  inv.emplace_back(&a);
  return true;
}

bool Container::pickUpItem(Entity &item_entity, Entity &using_entity){
  if ( using_entity.container && using_entity.container->addItem(item_entity) ) {
    for(unsigned i = 0; i < Game::actors.size(); ++i){
      if(Game::actors[i].get() == &item_entity){
	Game::actors.erase(Game::actors.begin()+i);
	break;
      }
    }
    return true;
  }
  return false;
}

bool Container::removeItem(Entity &a){
  //  inv.remove(&a);
    
  
  for(unsigned i = 0; i < inv.size(); ++i){
    if(inv[i] == &a){
      inv.erase(inv.begin()+i);
      return true;
    }
  }
  
  return false;
}

Container::Container(unsigned size) : size(size){
  
}
