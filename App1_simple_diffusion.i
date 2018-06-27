[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmax = 100
  ymax = 100
[]

[Variables]
  [./T] #temperature field
    order = FIRST
    family = LAGRANGE
  [../]
[]

[ICs]
  [./Center_circle]
    type = SmoothCircleIC
    variable = T
    x1 = 50
    y1 = 50
    radius = 5
    int_width = 1
    invalue = 10
    outvalue = 0
  [../]
[]

[BCs]
  #Specifying nothing: no-flux BC
  [./zero_bc]
    type = DirichletBC
    variable = T
    value = 0
    boundary = 'top right'
  [../]
[]

[Kernels]
  [./Time_derivative_T]
    type = TimeDerivative
    variable = T
  [../]
  [./divergence_term]
    type = Diffusion
    variable = T
  [../]
  [./Source_term]
    type = BodyForce
    variable = T
    function = delta_function
    value = 1
  [../]
[]

[Functions]
  [./delta_function]
    type = ParsedFunction
    value = 'r := (x-xc)^2 + (y-yc)^2 - radi^2; if(r <= 0, 1, 0)'
    vars = 'xc yc radi'
    vals = '30 30 2'
  [../]
[]

[Preconditioning]
  [./Getting_off_diagonal_Jacobian]
    type = SMP
    full = true
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
