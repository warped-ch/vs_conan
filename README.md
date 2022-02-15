# Visual Studio with Conan
Native Visual Studio [Conan][100] integration with Microsoft MSBuild, using properties files.

### Project structure:
- static_lib_a
  - src: static library code
  - test: unit test project using [GoogleTest][200]

## Prerequisites
1. Install [Conan](https://docs.conan.io/en/latest/installation.html)

## Get it running
Steps required to get it running using Visual Studio 2017

1. create Conan profiles
    
    https://docs.conan.io/en/latest/reference/profiles.html#profiles

    1.1. generate Visual Studio 2017 x64 debug profile:
    ```
    conan profile new vs2017_x64_debug --detect
    ```
    modify the generated profile `<userhome>\.conan\profiles\vs2017_x64_debug` to match the following specs (especially `compiler.version` and `build_type`)
    ```
    [settings]
    os=Windows
    os_build=Windows
    arch=x86_64
    arch_build=x86_64
    compiler=Visual Studio
    compiler.version=15
    build_type=Debug
    [options]
    [build_requires]
    [env]
    ``` 

    1.2. generate Visual Studio 2017 x64 release profile:
    ```
    conan profile new vs2017_x64_release --detect
    ```
    modify the generated profile `<userhome>\.conan\profiles\vs2017_x64_release` to match the following specs
    ```
    [settings]
    os=Windows
    os_build=Windows
    arch=x86_64
    arch_build=x86_64
    compiler=Visual Studio
    compiler.version=15
    build_type=Release
    [options]
    [build_requires]
    [env]
    ```

1. Install the requirements
    ```
    <repository_root>\conan>conan install . -pr=vs2017_x64_debug
    ```
    ```
    <repository_root>\conan install . -pr=vs2017_x64_release
    ```

1. build, run & have fun

## Project setup
1. Using the Conan `visual_studio_multi` generator to create a MSBuild properties `conanbuildinfo_multi.props` file
  
    - add the `visual_studio_multi` generator in the `conanfile.txt`:
      ```
      [generators]
      visual_studio_multi
      ```
    - Install the requirements (see steps above)
    - Add the `conanbuildinfo_multi.props` to `static_lib_a_test` test project
      - Visual Studio project
      - View
      - select `static_lib_a_test`
      - `Add Existing Property Sheet` icon above
      - select `conanbuildinfo_multi.props` from `conan` folder in repository root directory

## Resources
* [Conan][100]
  * [Documentation][101]
  * [Profiles][102]
  * [MSBuild (Visual Studio)][103]
* [GoogleTest][200]
  * [Documentation][201]
  * [gtest on ConanCenter][202]

[100]: https://conan.io/
[101]: https://docs.conan.io/en/latest/index.html
[102]: https://docs.conan.io/en/latest/reference/profiles.html#profiles
[103]: https://docs.conan.io/en/latest/integrations/build_system/msbuild.html#
[200]: https://github.com/google/googletest
[201]: https://google.github.io/googletest/
[202]: https://conan.io/center/search/gtest
