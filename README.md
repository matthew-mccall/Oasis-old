**This is the old version of the project! The new one is at [matthew-mccall/Oasis](https://github.com/matthew-mccall/Oasis).**

# Oasis

Open Algebra Software for Inferring Solutions

## Building

Oasis (library) includes the source (and licenses to redistribute the sources) for its dependencies in tree. Therefore,
the
projects depends on nothing more than CMake to build.

### Desktop

If you are building Oasis Desktop
app, [install wxWidgets 3 or newer](https://docs.wxwidgets.org/3.2/overview_install.html). Then
pass `-DBUILD_OASIS_DESKTOP=ON` to CMake during the generation step.
