# Master app
[MultiApps]
  [./diffusion]
    type = TransientMultiApp
    app_type = multiapp_dukimApp
    execute_on = TIMESTEP_BEGIN
    positions = '0   0   0
                 100 0   0
                 0   100 0
                 100 100 0'
    input_files = '../multiapp_app1/App1_simple_diffusion.i'
  [../]
[]
