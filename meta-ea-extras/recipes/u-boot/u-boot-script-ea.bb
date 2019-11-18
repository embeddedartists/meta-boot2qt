############################################################################
##
## Copyright (C) 2018 The Qt Company Ltd.
## Contact: https://www.qt.io/licensing/
##
## This file is part of the Boot to Qt meta layer.
##
## $QT_BEGIN_LICENSE:GPL$
## Commercial License Usage
## Licensees holding valid commercial Qt licenses may use this file in
## accordance with the commercial license agreement provided with the
## Software or, alternatively, in accordance with the terms contained in
## a written agreement between you and The Qt Company. For licensing terms
## and conditions see https://www.qt.io/terms-conditions. For further
## information use the contact form at https://www.qt.io/contact-us.
##
## GNU General Public License Usage
## Alternatively, this file may be used under the terms of the GNU
## General Public License version 3 or (at your option) any later version
## approved by the KDE Free Qt Foundation. The licenses are as published by
## the Free Software Foundation and appearing in the file LICENSE.GPL3
## included in the packaging of this file. Please review the following
## information to ensure the GNU General Public License requirements will
## be met: https://www.gnu.org/licenses/gpl-3.0.html.
##
## $QT_END_LICENSE$
##
############################################################################

LICENSE = "The-Qt-Company-Commercial"
LIC_FILES_CHKSUM = "file://${BOOT2QTBASE}/licenses/The-Qt-Company-Commercial;md5=948f8877345cd66106f11031977a4625"
DEPENDS = "u-boot-mkimage-native"

PV = "1.0"

SRC_URI = " \
    file://bootscript.txt \
    "

S = "${WORKDIR}"

inherit deploy

do_mkimage () {
    uboot-mkimage -A arm -O linux -T script -C none -a 0 -e 0 \
                  -n "EA BootScript" -d ${WORKDIR}/bootscript.txt \
                  ${S}/boot.scr
}

addtask mkimage after do_compile before do_install

do_deploy () {
    install -d ${DEPLOYDIR}/${MACHINE}
    install -m 0644 -t ${DEPLOYDIR} ${S}/*.scr
}

addtask deploy after do_install before do_build

do_compile[noexec] = "1"
do_install[noexec] = "1"

PACKAGE_ARCH = "${MACHINE_ARCH}"
COMPATIBLE_MACHINE = "(imx6qea-com|imx8mmea-ucom)"
