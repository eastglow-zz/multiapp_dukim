//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef MULTIAPP_DUKIMTESTAPP_H
#define MULTIAPP_DUKIMTESTAPP_H

#include "MooseApp.h"

class multiapp_dukimTestApp;

template <>
InputParameters validParams<multiapp_dukimTestApp>();

class multiapp_dukimTestApp : public MooseApp
{
public:
  multiapp_dukimTestApp(InputParameters parameters);
  virtual ~multiapp_dukimTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* MULTIAPP_DUKIMTESTAPP_H */
