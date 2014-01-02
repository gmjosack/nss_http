# nss\_http

## Description

This is a simple Name Service Switch module that I wrote in order to quickly
extend nss via an HTTP server that runs on localhost. This is seriously not
meant to be used in a production environment. Not only is it inefficient but
I'm extremely rusty with C. Use at your own enjoyment.

## Installation

In the `libnss_http` directory:
```
make
sudo make install
```

You'll need to have `libjansson` and `libcurl` installed.

## Configuration

Once the module is installed on your system you just have to modify the
`/etc/nsswitch.conf` for the appropriate service you want to utilize the 
http server on. The service name is `http` and currently supports the `passwd`, `group`,
`shadow` databases.

e.g. `/etc/nsswitch.conf`
```
passwd:         http compat
group:          http compat
shadow:         http compat
```

## API

By default `nss_http` expects a server to be listening on `127.0.0.1:9669`. This is compiled in
and can be modified in the nss_http.h file. I have provided an example server in the `examples`
directory though I'll describe the API below.

### Endpoints

#### /passwd

The `/passwd` endpoint should return an array of password objects as described below:

```javascript
[
    {
        pw_name: "gary",
        pw_passwd: "x",
        pw_uid: 100,
        pw_gid: 100,
        pw_gecos: "User Information",
        pw_dir: "/home/gary",
        pw_shell: "/bin/bash"
    }
]
```

See `man 3 getpwent` for more information about the passwd struct.

The passwd endpoint should expect to receive 1 of 2 mutually exclusive query parameters. `name`,
containing a username or `uid` containing a user id. If either of these query parameters are
received, a single object should be returned for the requested username/uid.


#### /group

The `/group` endpoint should return an array of group objects as described below:

```javascript
[
    {
        gr_name: "users",
        gr_passwd: "x",
        gr_gid: 101,
        gr_mem: ["gary", "carolyn"]
    }
]
```

See `man 3 getgrent` for more information about the group struct.

The group endpoint should expect to receive 1 of 2 mutually exclusive query parameters. `name`,
containing a username or `gid` containing a group id. If either of these query parameters are
received, a single object should be returned for the requested groupname/gid.

#### /shadow

The `/shadow` endpoint should return an array of shadow objects as described below:

```javascript
[
    {
        sp_namp: "gary",
        sp_pwdp: "<encrypted password>",
        sp_lstchg: 16034,
        sp_min: 0,
        sp_max: 99999,
        sp_warn: 7,
        sp_inact: null,
        sp_expire: null,
        sp_flag: null
    }
]
```

See `man 3 getspent` for more information about the shadow struct.

The shadow endpoint should expect to receive a query parameter of `name`,
containing a username. If this query parameter is received, a single object
 should be returned for the requested username.
