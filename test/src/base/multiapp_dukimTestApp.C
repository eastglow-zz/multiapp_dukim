//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "multiapp_dukimTestApp.h"
#include "multiapp_dukimApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<multiapp_dukimTestApp>()
{
  InputParameters params = validParams<multiapp_dukimApp>();
  return params;
}

multiapp_dukimTestApp::multiapp_dukimTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  multiapp_dukimApp::registerObjectDepends(_factory);
  multiapp_dukimApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  multiapp_dukimApp::associateSyntaxDepends(_syntax, _action_factory);
  multiapp_dukimApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  multiapp_dukimApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    multiapp_dukimTestApp::registerObjects(_factory);
    multiapp_dukimTestApp::associateSyntax(_syntax, _action_factory);
    multiapp_dukimTestApp::registerExecFlags(_factory);
  }
}

multiapp_dukimTestApp::~multiapp_dukimTestApp() {}

void
multiapp_dukimTestApp::registerApps()
{
  registerApp(multiapp_dukimApp);
  registerApp(multiapp_dukimTestApp);
}

void
multiapp_dukimTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
multiapp_dukimTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
multiapp_dukimTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
multiapp_dukimTestApp__registerApps()
{
  multiapp_dukimTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
multiapp_dukimTestApp__registerObjects(Factory & factory)
{
  multiapp_dukimTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
multiapp_dukimTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  multiapp_dukimTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
multiapp_dukimTestApp__registerExecFlags(Factory & factory)
{
  multiapp_dukimTestApp::registerExecFlags(factory);
}
