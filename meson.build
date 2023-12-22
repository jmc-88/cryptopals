project(
    'cryptopals',
    'cpp',
    version: '0.1',
    default_options: ['warning_level=3', 'cpp_std=c++17'],
)

data_path = join_paths(meson.current_source_dir(), 'data')
define_data_path = f'-D_DATA_PATH="@data_path@"'

libcrypto = library(
    'crypto',
    [
        'lib/ascii.cc',
        'lib/base64.cc',
        'lib/bitwise.cc',
        'lib/frequency.cc',
        'lib/hex.cc',
    ],
    install: true,
)

test(
    'ascii',
    executable('ascii_test', 'lib/ascii_test.cc', link_with: libcrypto),
)

test(
    'base64',
    executable('base64_test', 'lib/base64_test.cc', link_with: libcrypto),
)

test(
    'bitwise',
    executable('bitwise_test', 'lib/bitwise_test.cc', link_with: libcrypto),
)

test(
    'frequency',
    executable('frequency_test', 'lib/frequency_test.cc', link_with: libcrypto),
)

test(
    'hex',
    executable('hex_test', 'lib/hex_test.cc', link_with: libcrypto),
)

test(
    'set1_challenge1',
    executable('set1_challenge1', 'src/set1/challenge1.cc', link_with: libcrypto),
)

test(
    'set1_challenge2',
    executable('set1_challenge2', 'src/set1/challenge2.cc', link_with: libcrypto),
)

test(
    'set1_challenge3',
    executable('set1_challenge3', 'src/set1/challenge3.cc', link_with: libcrypto),
)

test(
    'set1_challenge4',
    executable(
        'set1_challenge4',
        'src/set1/challenge4.cc',
        cpp_args: [define_data_path],
        link_with: libcrypto,
    ),
)
