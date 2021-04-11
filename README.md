# u8ility
It's a simple optimistic library to handle cpp UTF-8 encoded strings, with an example of how it is supposed to be used at the current time (rolling with further development) 🤞

## What you can do (at this time)

 - encode and decode from the corresponding Unicode code point. ( *mstr::encode* and *mstr::decode* )
 - wrap an UTF-8 string (i.e.  u8"blahblah")  into an *mstr*
 - get underlying representation of *mstr* as a vector of *mchar*
 - iteratively increment an *mchar* instance

## TODO

 - provide other operators 
 - provide algs
 - ... (several things, just too much to list them all 😂)
