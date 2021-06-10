project('golsim', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

sfmldep = dependency('sfml-all')

executable('pyaniyasteroid',
           'main.cpp',
           'gamer.cpp',
           'game.cpp',
           'gamestate.cpp',
           dependencies: sfmldep,
           install : true)
