# https://stackoverflow.com/questions/9772036/pass-all-variables-from-one-shellscript-to-another
DYLD_FALLBACK_LIBRARY_PATH=".:$OSG_LIB_DIR"
(
  export DYLD_FALLBACK_LIBRARY_PATH
  cd build/bin
  ./osg_tools_test --abort --use-colour=yes --durations=no
)
