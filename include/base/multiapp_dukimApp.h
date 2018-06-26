//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef MULTIAPP_DUKIMAPP_H
#define MULTIAPP_DUKIMAPP_H

#include "MooseApp.h"

class multiapp_dukimApp;

template <>
InputParameters validParams<multiapp_dukimApp>();

class multiapp_dukimApp : public MooseApp
{
public:
  multiapp_dukimApp(InputParameters parameters);
  virtual ~multiapp_dukimApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void registerObjectDepends(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void associateSyntaxDepends(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* MULTIAPP_DUKIMAPP_H */
