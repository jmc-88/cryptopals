project(
    'cryptopals',
    'cpp',
    version: '0.1',
    default_options: ['warning_level=3', 'cpp_std=c++17'],
)

libcrypto = library(
    'crypto',
    [
        'lib/base64.cc',
        'lib/bitwise.cc',
        'lib/hex.cc',
    ],
    install: true,
)

test(
    'base64',
    executable('base64', 'lib/base64_test.cc', link_with: libcrypto),
)

test(
    'bitwise',
    executable('bitwise', 'lib/bitwise_test.cc', link_with: libcrypto),
)

test(
    'hex',
    executable('hex', 'lib/hex_test.cc', link_with: libcrypto),
)

test(
    'set1_challenge1',
    executable('set1_challenge1', 'src/set1/challenge1.cc', link_with: libcrypto),
)

test(
    'set1_challenge2',
    executable('set1_challenge2', 'src/set1/challenge2.cc', link_with: libcrypto),
)
