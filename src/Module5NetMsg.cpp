#include "NetMsgCreateWO.h"
#ifdef AFTR_CONFIG_USE_BOOST

#include <iostream>
#include <sstream>
#include <string>
#include "AftrManagers.h"
#include "Vector.h"
#include "WO.h"
#include "GLView.h"
#include "WorldContainer.h"
#include "Module5NetMsg.h"
#include "GLViewNewModule.h"

using namespace Aftr;

NetMsgMacroDefinition(Module5NetMsg);

Module5NetMsg::Module5NetMsg()
{
//	this->antSetbackCourse = 0;
}

Module5NetMsg::~Module5NetMsg()
{
}

//need to write
bool Module5NetMsg::toStream(NetMessengerStreamBuffer& os) const
{
//	os << this->antSetbackCourse;
	os << this->id;
	//os << this->scale;
	os << this->pos.x;
	os << this->pos.y;
	os << this->pos.z;
	return true;
}

//need to write
bool Module5NetMsg::fromStream(NetMessengerStreamBuffer& is)
{
//	is >> this->antSetbackCourse;
	is >> this->id;
	//is >> this->scale;
	is >> this->pos.x;
	is >> this->pos.y;
	is >> this->pos.z;
	return true;
}

//need to write
void Module5NetMsg::onMessageArrived()
{

	GLViewNewModule* glView = ((GLViewNewModule*)ManagerGLView::getGLView());
	WorldContainer* wc = glView->getWorldContainer();

	//just realized I've got no way of reading data that has been recieved
	//so many hours wasted :-))))
	//WO* wo = wc->getWOByID(wc->size() - 1);
	
	glView->createRandomBoxes();

}

//need to write
std::string Module5NetMsg::toString() const
{
	std::stringstream ss;

	ss << NetMsg::toString();
	ss << "Payload: ID = " << this->id << "\n";
	//ss << "Payload: Scale = " << this->scale << "\n";
	ss << "Payload: Position = {" << this->pos.x << ", " << this->pos.y << ", " << this->pos.z << "}\n";

	return ss.str();
}

#endif