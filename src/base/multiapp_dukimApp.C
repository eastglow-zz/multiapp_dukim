#include "multiapp_dukimApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<multiapp_dukimApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

multiapp_dukimApp::multiapp_dukimApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  multiapp_dukimApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  multiapp_dukimApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  multiapp_dukimApp::registerExecFlags(_factory);
}

multiapp_dukimApp::~multiapp_dukimApp() {}

void
multiapp_dukimApp::registerApps()
{
  registerApp(multiapp_dukimApp);
}

void
multiapp_dukimApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"multiapp_dukimApp"});
}

void
multiapp_dukimApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"multiapp_dukimApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
multiapp_dukimApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
multiapp_dukimApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
multiapp_dukimApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
multiapp_dukimApp__registerApps()
{
  multiapp_dukimApp::registerApps();
}

extern "C" void
multiapp_dukimApp__registerObjects(Factory & factory)
{
  multiapp_dukimApp::registerObjects(factory);
}

extern "C" void
multiapp_dukimApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  multiapp_dukimApp::associateSyntax(syntax, action_factory);
}

extern "C" void
multiapp_dukimApp__registerExecFlags(Factory & factory)
{
  multiapp_dukimApp::registerExecFlags(factory);
}
