# Sample xt tables module and library (incomplete)

## Build
```
sudo apt install -y libxtables-dev
make
```

## Running
```
make up # load module
sudo XTABLES_LIBDIR=$(pwd):/usr/lib/x86_64-linux-gnu/xtables/  iptables -A INPUT -m demo -j LOG
# ...
sudo iptables -F
make down
```


## References

[Writing Netfilter Modules](https://inai.de/documents/Netfilter_Modules.pdf)
