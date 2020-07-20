BOX_BRAND = "minix"

# MINIX BSP default settings
LINUX_VERSION_EXTENSION ?= ""

PREFERRED_PROVIDER_jpeg = "libjpeg-turbo"
PREFERRED_PROVIDER_jpeg-native = "libjpeg-turbo-native"

DVBMEDIASINK_CONFIG = "--with-wmv --with-pcm --with-eac3 --with-h265 --with-dtsdownmix"

EXTRA_OECONF_append_pn-enigma2 = " --with-alsa --with-alsacard=hw:0 --with-alsamixer=Master --with-fbdev=/dev/fb0 --with-lcddev=/dev/null --with-amlogic"
DEPENDS_append_pn-enigma2 = " libdvbcsa minix-libamcodec-${MACHINE} minix-libamadec-${MACHINE}"
EXTRA_OECONF_append_pn-tuxtxt-enigma2 = " --with-fbdev=/dev/fb0"
CC_append_pn-showiframe = " -DHAVE_AMLOGIC -I${STAGING_INCDIR}/amlogic/amcodec -lamcodec"
DEPENDS_append_pn-showiframe = " minix-libamcodec-${MACHINE}"

GST_VERSION = "0.10"

SOC_FAMILY = "AML8726"

IMAGE_CLASSES += "image_types_minix"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	minix-gst-amlavsink \
	minix-gst-app \
	minix-gst-amlavout \
	gst-fluendo-mpegdemux \
	kernel-module-stb-procfs \
	kernel-module-stb-nimsockets \
	kernel-modules \
	minix-amlsetfb \
	amremote \
	firmware-ap6330 \
	"

DVBPROVIDER = "kernel"

MACHINE_EXTRA_RRECOMMENDS += "\
	minix-libamplayer-${MACHINE} \
	minix-libamavutils-${MACHINE} \
	minix-libamadec-${MACHINE} \
	minix-libamcodec-${MACHINE} \
	"

KERNEL_MODULE_AUTOLOAD += "\
	stb-procfs \
	stb-nimsockets \
	sysfillrect \
	syscopyarea \
	mceusb \
	rc-core \
	mali \
	dhd \
	ch341 \
	rfcomm \
	hidp \
	aml_pmu_dev \
	xfs \
	"

# Uncomment the following line to enable the hard floating point abi. Note that
# this breaks some binary libraries and 3D (neither of which ship with
# meta-yocto). For maximum compatibility, leave this disabled.
DEFAULTTUNE ?= "cortexa9hf-neon"
require conf/machine/include/tune-cortexa9.inc

IMAGE_FSTYPES += "sdcard"
IMAGE_ROOTFS_SIZE = "976562"
IMAGE_EXTRA_SPACE = "0"
IMAGE_OVERHEAD_FACTOR = "1.0"

# Serial console to be used
SERIAL_CONSOLE = "115200 ttyS0"

PREFERRED_PROVIDER_virtual/kernel = "linux-minix"
PREFERRED_VERSION_linux-wetek = "3.10.93"

KERNEL_IMAGETYPE = "uImage"
KERNEL_DEVICETREE = "meson8m2_n200_2G.dtd meson8m2_n200_2G.dtb"

#specify u-boot parameters
PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot-hardkernel"
PREFERRED_PROVIDER_u-boot ?= "u-boot-hardkernel"
PREFERRED_VERSION_u-boot-hardkernel ?= "2015.01"

UBOOT_MACHINE = "odroidc2_defconfig"

UBOOT_ENTRYPOINT  = "0x80008000"
UBOOT_LOADADDRESS = "0x80008000"

IMAGE_CMD_sdcard_append = "\
    mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
    mv ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.img ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${IMAGE_NAME}.img; \
    echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
    cd ${DEPLOY_DIR_IMAGE}; \
    zip ${IMAGE_NAME}_sdcard.zip ${IMAGEDIR}/*; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.ext4; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.img; \
    rm -Rf ${IMAGEDIR}; \
    "

MACHINE_FEATURES = "bluetooth fb meson8 usbhost vfat alsa dvb-c nolcd nogamma nofhdskin HDMI"

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"
