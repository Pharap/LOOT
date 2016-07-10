#pragma once

// Macros are usually evil,
// but this is legitimate use because
// we definately want the debug code removed.
// (Also I can't be bothered to mess around with trying
// to get the template equivalent version correct)

#if defined(DEBUG)
  // If in debug mode, use assert functionality
  #define DEBUG_ASSERT(x) assert(x)
#else // Release version
  // Release mode, hide all the debug assertions
  #define DEBUG_ASSERT(x)
#endif
