[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmax = 100
  ymax = 100
[]

[Variables]
  [./dummy]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[AuxVariables]
  [./Source_from_App2]
    order = FIRST
    family = LAGRANGE
  [../]

  [./Diffusion_field_from_App1]
    order = FIRST
    family = LAGRANGE
  [../]
[]

[ICs]
  [./zero_IC]
    type = ConstantIC
    variable = dummy
    value = 0
  [../]
[]

[BCs]
  [./zero_BC]
    type = DirichletBC
    variable = dummy
    value = 0
    boundary = 'top bottom left right'
  [../]
[]

[Kernels]
  [./var_itself]
    type = MassEigenKernel
    variable = dummy
    eigen = false
  [../]
  [./diffusion_data]
    type = BodyForce
    variable = dummy
    #value = Diffusion_field_from_App1
    value = 0
    #function = Diffusion_field_from_data
  [../]
[]

[Executioner]
  type = Transient
  solve_type = NEWTON

  petsc_options_iname = '-pc_type -sub_pc_type'
  petsc_options_value = 'asm      lu          '

  l_max_its = 30
  l_tol = 1e-4
  nl_max_its = 50
  nl_rel_tol = 1e-8

  [./TimeStepper]
    type = IterationAdaptiveDT
    dt=1
  [../]
[]

[Outputs]
  exodus = true
[]

# Master app
[MultiApps]
  [./sourceterm]
    type = TransientMultiApp
    app_type = multiapp_dukimApp
    execute_on = TIMESTEP_BEGIN
    positions = '0 0 0'
    input_files = App2_simple_source.i
  [../]
  [./diffusion]
    type = TransientMultiApp
    app_type = multiapp_dukimApp
    execute_on = TIMESTEP_BEGIN
    positions = '0   0   0'
    input_files = App1_simple_diffusion.i
  [../]
[]

[Transfers]
  [./App2_to_master]
    type = MultiAppNearestNodeTransfer
    direction = from_multiapp
    multi_app = sourceterm
    source_variable = S  # This S is defined in App2_simple_source.i
    variable = Source_from_App2
    execute_on = SAME_AS_MULTIAPP
  [../]
  [./master_to_App1]
    type = MultiAppNearestNodeTransfer
    direction = to_multiapp
    multi_app = diffusion
    source_variable = Source_from_App2
    variable = S  # This S is defined in App1_simple_diffusion.i
    execute_on = SAME_AS_MULTIAPP
  [../]
  [./App1_to_master]
    type = MultiAppNearestNodeTransfer
    direction = from_multiapp
    multi_app = diffusion
    source_variable = T # T is defined in App1_simple_diffusion.i
    variable = Diffusion_field_from_App1
    execute_on = SAME_AS_MULTIAPP
  [../]
[]
