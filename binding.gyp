{
  'targets': [{
    'target_name': 'testlib',
    'include_dirs': [
      '<!@(node -p "require(\'node-addon-api\').include")',
    ],
    'dependencies': ["<!(node -p \"require('node-addon-api').gyp\")"],
    'conditions': [
      ['OS == "mac"', {
        'include_dirs': [
          'System/Library/Frameworks/ApplicationServices.framework/Headers'
        ],
        'link_settings': {
          'libraries': [
            '-framework ApplicationServices',
          ]
        }
      }],
    ],
    'defines': [ 'NAPI_CPP_EXCEPTIONS' ],
    'cflags!': [ '-fno-exceptions' ],
    'cflags_cc!': [ '-fno-exceptions' ],
    'msvs_settings': {
      'VCCLCompilerTool': {
        'ExceptionHandling': 1,
        'EnablePREfast': 'true',
      },
    },
    'xcode_settings': {
      'CLANG_CXX_LIBRARY': 'libc++',
      'MACOSX_DEPLOYMENT_TARGET': '10.7',
      'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
    },
    'sources': [
      'main.cpp',
    ]
  }]
}
