[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmax = 100
  ymax = 100
[]

[Variables]
  [./S] #Source data
    order = FIRST
    family = LAGRANGE
  [../]
[]

[ICs]
  [./Initial_position]
    type = ConstantIC
    variable = S
    value = 0
  [../]
[]

[BCs]
  [./zero_BC]
    type = DirichletBC
    variable = S
    value = 0
    boundary = 'top bottom left right'
  [../]
[]

[Kernels]
  #[./TimeDerivative]
  #  type = TimeDerivative
  #  variable = S
  #[../]
  #[./diffusion]
  #  type = Diffusion
  #  variable = S
  #[../]
  [./variable_itself]
    type = MassEigenKernel
    variable = S
    eigen = false
  [../]
  [./traveling_deltafunction]
    type = BodyForce
    variable = S
    value = 1
    function = delta_function
  [../]
[]

[Functions]
  [./delta_function]
    type = ParsedFunction
    value = 'rot_radi:=30+15*sin(4*w*t);x1:=50+rot_radi*cos(w*t);y1:=50+rot_radi*sin(w*t);r:=(x-x1)^2+(y-y1)^2-size_radi^2;if(r <= 0, -1, 0)'
    vars = 'w    size_radi'
    vals = '0.1  2'
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
  #l_tol = 0.999999
  #nl_max_its = 50
  #nl_rel_tol = 0.999999
  dt = 0.1
  #[./TimeStepper]
  #  type = IterationAdaptiveDT
  #  dt=1
  #[../]
[]

[Outputs]
  exodus = true
[]
