# flyconfig:  A lib for managing config file by C++

* requirements:

** data type supported: string, int, float
** comment (start with '#')
** config format: key(config name) type_flag(s,i,f) value(config value) 
** if it's not comment, the first word is key and second word is type flag, 
rest is value whose spaces will be ignored.
** for type_flag, s means string, i means int and f means float.
** ignore empty line and comments.


* example:

``` a.flyconfig

# it's user's name
user_name s Thank Fly
user_age i 21
user_height f 170.3

```
this config will function like this.

``` c++
FlyConfig config("a.flyconfig");
string un = config.get("user_name");   // un: "Thank Fly"
int    ua = config.get("user_age");    // ua: 21
float  uh = config.get("user_height"); // uh: 170.3
```

