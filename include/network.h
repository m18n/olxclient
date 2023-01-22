#pragma once
#include "client.h"
using namespace client;
extern Client cl;
class RES_auth: public pack_res{
  private:
  std::string name;
  std::string password;
  public:
  RES_auth(){
    idpack=1;
  }
  pars::json_construct GetJsonPack() override{
    pars::json_construct json;
    pars::json_item name;
    name.init("name",this->name);
    pars::json_item password;
    password.init("password",this->password);
    json.addelement(name);
    json.addelement(password);
    return json;
  }
};

class REQ_status : public pack_req {
 private:
  int code;

 public:
  bool JsonToData(json_value* json) override{
    json_object_entry* jcode = pars::jsonGetNameKey(json, "code");
    if (jcode != NULL && jcode->value->type == json_integer) {
      code = jcode->value->u.integer;
      return true;
    }
    return false;
  }
  void ProcessPack() override { printf("STATUS: %d\n", code); }
  void InitPack() override{
    idpack = 10;
    code = 0;
  }
};
void ConnectMainServer();