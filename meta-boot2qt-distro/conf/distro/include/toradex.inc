############################################################################
##
## Copyright (C) 2019 The Qt Company Ltd.
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

include conf/distro/include/fsl.inc

# include file from meta-toradex-nxp
require conf/machine/include/${MACHINE}.inc

BBMASK += "\
   meta-toradex-nxp/recipes-graphics/xorg-xserver \
   meta-toradex-nxp/recipes-multimedia/gstreamer \
   meta-toradex-bsp-common/recipes-devtools/python \
   meta-toradex-bsp-common/recipes-devtools/e2fsprogs \
   meta-toradex-bsp-common/recipes-core/systemd \
   "

PREFERRED_PROVIDER_u-boot = "u-boot-toradex"

WKS_FILE_DEPENDS += "u-boot-script-toradex"

MACHINEDIR = "${@d.getVar('MACHINE').replace('-','_')}"
IMAGE_BOOT_FILES += " \
    fwd_blk.img;flash_blk.img \
    fwd_eth.img;flash_eth.img \
    fwd_mmc.img;flash_mmc.img \
    ${MACHINE}/*;${MACHINEDIR}/ \
    "

# use 1.14.0 that matches the imx version of gstreamer
PREFERRED_VERSION_gstreamer1.0-plugins-ugly = "1.14.0"
PREFERRED_VERSION_gstreamer1.0-libav = "1.14.0"

# override tezi bbclass
IMAGE_CLASSES_remove = " image_type_tezi"
IMAGE_CLASSES_append = " image_type_tezi_thud"
