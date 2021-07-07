project('golsim', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

sfmldep = dependency('sfml-all')

executable('pyaniyasteroid',
           'main.cpp',
           'game.cpp',
           'gamer.cpp',
           'gamestate.cpp',
           'bullet.cpp',
           'grifer.cpp',
           dependencies: sfmldep,
           install : true)

assetcopy = find_program('scripts/assetcopy.sh')

run_command(assetcopy)