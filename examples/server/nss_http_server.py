#!/usr/bin/env python

import json
from flask import Flask, request, abort, Response

app = Flask(__name__)


@app.route('/passwd')
def passwd():
    data = [
        {
            "pw_name": "testuser1", "pw_passwd": "x", "pw_uid": 6000, "pw_gid": 6000,
            "pw_gecos": "Testing", "pw_dir": "/home/testuser1", "pw_shell": "/bin/bash",
        },
        {
            "pw_name": "testuser2", "pw_passwd": "x", "pw_uid": 6001, "pw_gid": 6000,
            "pw_gecos": None, "pw_dir": "/home/testuser2", "pw_shell": "/bin/bash",
        },
        {
            "pw_name": "testuser3", "pw_passwd": "x", "pw_uid": 6002, "pw_gid": 6001,
            "pw_gecos": None, "pw_dir": "/home/testuser3", "pw_shell": "/bin/bash",
        },
        {
            "pw_name": "testuser4", "pw_passwd": "x", "pw_uid": 6003, "pw_gid": 6001,
            "pw_gecos": None, "pw_dir": "/home/testuser4", "pw_shell": "/bin/bash",
        },
    ]

    name = request.args.get("name")
    if name:
        for struct in data:
            if name == struct["pw_name"]:
                return Response(json.dumps(struct),  mimetype='application/json')
        abort(404)

    uid = request.args.get("uid")
    if uid:
        uid = int(uid)
        for struct in data:
            if uid == struct["pw_uid"]:
                return Response(json.dumps(struct),  mimetype='application/json')
        abort(404)

    return Response(json.dumps(data),  mimetype='application/json')


@app.route('/group')
def group():
    data = [
        { "gr_name": "testgroup1", "gr_passwd": "x", "gr_gid": 6000, "gr_mem": ["testuser1", "testuser2"], },
        { "gr_name": "testgroup2", "gr_passwd": "x", "gr_gid": 6001, "gr_mem": ["testuser3", "testuser4"], },
    ]

    name = request.args.get("name")
    if name:
        for struct in data:
            if name == struct["gr_name"]:
                return Response(json.dumps(struct),  mimetype='application/json')
        abort(404)

    gid = request.args.get("gid")
    if gid:
        gid = int(gid)
        for struct in data:
            if gid == struct["gr_gid"]:
                return Response(json.dumps(struct),  mimetype='application/json')
        abort(404)

    return Response(json.dumps(data),  mimetype='application/json')


@app.route('/shadow')
def shadow():
    data = [
        {
            "sp_namp": "testuser1", "sp_pwdp": "$1$BXZIu72k$S7oxt9hBiBl/O3Rm3H4Q30", "sp_lstchg": 16034,
            "sp_min": 0, "sp_max": 99999, "sp_warn": 7, "sp_inact": None, "sp_expire": None, "sp_flag": None,
        },
        {
            "sp_namp": "testuser2", "sp_pwdp": "$1$BXZIu72k$S7oxt9hBiBl/O3Rm3H4Q30", "sp_lstchg": 16034,
            "sp_min": 0, "sp_max": 99999, "sp_warn": 7, "sp_inact": None, "sp_expire": None, "sp_flag": None,
        },
        {
            "sp_namp": "testuser3", "sp_pwdp": "$1$BXZIu72k$S7oxt9hBiBl/O3Rm3H4Q30", "sp_lstchg": 16034,
            "sp_min": 0, "sp_max": 99999, "sp_warn": 7, "sp_inact": None, "sp_expire": None, "sp_flag": None,
        },
        {
            "sp_namp": "testuser4", "sp_pwdp": "$1$BXZIu72k$S7oxt9hBiBl/O3Rm3H4Q30", "sp_lstchg": 16034,
            "sp_min": 0, "sp_max": 99999, "sp_warn": 7, "sp_inact": 10, "sp_expire": 50, "sp_flag": None,
        },
    ]

    name = request.args.get("name")
    if name:
        for struct in data:
            if name == struct["sp_namp"]:
                return Response(json.dumps(struct),  mimetype='application/json')
        abort(404)

    return Response(json.dumps(data),  mimetype='application/json')


if __name__ == "__main__":
    app.debug = True
    app.run(host="localhost", port=9669)
