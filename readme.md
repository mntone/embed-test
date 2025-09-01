# Embedded Static Library Sample

This repository demonstrates how to build an embedded static library (.a) using GitHub Actions and automatically publish it as a GitHub Release.

## Features

- Embedded C/C++ static library
- Automatic build via GitHub Actions
- Build artifacts (.a files) published to GitHub Releases
- Cross-compilation examples for ARM Cortex-M (e.g., Raspberry Pi Pico)

## Usage

1. Modify or add source code
2. Push changes to GitHub
3. GitHub Actions will automatically build the library
4. After a successful build, the `.a` file will be attached to a Release

## Directory Structure Example

```

.
├── .github/
│   └── workflows/
│       └── build.yml  # GitHub Actions workflow
├── cmake/             # CMake files
├── src/               # Source files
└── CMakeLists.txt     # CMake build configuration

````


## License

Embedded Static Library Sample is licensed under the MIT license - see the [LICENSE](https://github.com/mntone/embed-test/blob/main/LICENSE) file for details.
