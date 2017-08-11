##############################################################################
##
## Copyright (C) 2016 The Qt Company Ltd.
## Contact: http://www.qt.io/licensing/
##
## This file is part of the Boot to Qt meta layer.
##
## $QT_BEGIN_LICENSE:COMM$
##
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company. For licensing terms
## and conditions see http://www.qt.io/terms-conditions. For further
## information use the contact form at http://www.qt.io/contact-us.
##
## $QT_END_LICENSE$
##
##############################################################################

python enable_internal_build () {
    import socket
    try:
        socket.gethostbyname('yocto-cache.intra.qt.io')
    except:
        return

    e.data.setVar('ENABLE_QTQUICKCOMPILER', "1")
    e.data.setVar('SSTATE_MIRRORS', "file://.* http://yocto-cache.intra.qt.io/sstate-caches/${DISTRO_CODENAME}/PATH")
    e.data.setVar('PREMIRRORS', "\
        ftp://.*/.*   http://yocto-cache.intra.qt.io/sources/ \n \
        http://.*/.*  http://yocto-cache.intra.qt.io/sources/ \n \
        https://.*/.* http://yocto-cache.intra.qt.io/sources/ \n \
        bzr://.*/.*   http://yocto-cache.intra.qt.io/sources/ \n \
        cvs://.*/.*   http://yocto-cache.intra.qt.io/sources/ \n \
        git://.*/.*   http://yocto-cache.intra.qt.io/sources/ \n \
        gitsm://.*/.* http://yocto-cache.intra.qt.io/sources/ \n \
        hg://.*/.*    http://yocto-cache.intra.qt.io/sources/ \n \
        osc://.*/.*   http://yocto-cache.intra.qt.io/sources/ \n \
        p4://.*/.*    http://yocto-cache.intra.qt.io/sources/ \n \
        svk://.*/.*   http://yocto-cache.intra.qt.io/sources/ \n \
        svn://.*/.*   http://yocto-cache.intra.qt.io/sources/ \n \
        ")
}

addhandler enable_internal_build
enable_internal_build[eventmask] = "bb.event.ConfigParsed"
