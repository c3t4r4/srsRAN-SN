srsRAN
======

[![Build Status](https://app.travis-ci.com/srsran/srsRAN.svg?branch=master)](https://app.travis-ci.com/github/srsran/srsRAN)
[![Language grade: C/C++](https://img.shields.io/lgtm/grade/cpp/g/srsran/srsRAN.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/srsran/srsRAN/context:cpp)
[![Coverity](https://scan.coverity.com/projects/23045/badge.svg)](https://scan.coverity.com/projects/srsran)
======

Instalation on Ubuntu 20.04.4 LTS + bladeRF x40

```
sudo apt-get install bladerf git libbladerf-dev bladerf-fpga-hostedx40 libusb-1.0-0-dev libusb-1.0-0 build-essential cmake libncurses5-dev libtecla1 libtecla-dev pkg-config git wget libuhd-dev libuhd3.15.0 uhd-host libfftw3-dev libmbedtls-dev libboost-program-options-dev libconfig++-dev libsctp-dev libboost-system-dev libboost-test-dev libboost-thread-dev libqwt-qt5-dev qtbase5-dev
```

```
sudo /usr/lib/uhd/utils/uhd_images_downloader.py
```

```
mkdir ~/Project
```

```
cd ~/Project && git clone https://github.com/pothosware/SoapySDR.git && cd SoapySDR && git checkout tags/soapy-sdr-0.7.2 && mkdir build && cd build && cmake .. && make -j4 && sudo make install && sudo ldconfig
```

```
cd ~/Project && git clone https://github.com/myriadrf/LimeSuite.git && cd LimeSuite && git checkout tags/v20.01.0 && mkdir builddir && cd builddir && cmake ../ && make -j4 && sudo make install && sudo ldconfig && cd .. && cd udev-rules && sudo ./install.sh
```

```
cd ~/Project && git clone https://github.com/srsLTE/srsGUI.git && cd srsGUI && mkdir build && cd build && cmake ../ && make && sudo make install
```

For Last Release
======
```
cd ~/Project && git clone https://github.com/srsRAN/srsRAN.git && cd srsRAN && mkdir build && cd build && cmake ../ && make -j4 && sudo make install && sudo ldconfig && sudo ./srsran_install_configs.sh user
```

```
sudo nano /root/.config/srsran/enb.conf
```
```
[enb]
mcc = <yourMCC>
mnc = <yourMNC>
mme_addr = 127.0.1.100     ## or IP for external MME, eg. 192.168.1.10
gtp_bind_addr = 127.0.1.1  ## or local interface IP for external S1-U, eg. 192.168.1.3
s1c_bind_addr = 127.0.1.1  ## or local interface IP for external S1-MME, eg. 192.168.1.3
n_prb = 15
tm = 2
nof_ports = 2

[rf]
dl_earfcn = 1934
tx_gain = 80               ## this power seems to work best
rx_gain = 40
device_name = bladeRF
device_args = auto         ## does not work with anything other than 'auto'
```

```
sudo nano /root/.config/srsran/epc.conf
```

```
[mme]
mcc = <yourMCC>
mnc = <yourMNC>
mme_bind_addr = 127.0.1.100  ## or local interface IP for external S1-MME, eg. 192.168.1.10
```



For Release 19.12
======
```
cd ~/Project && git clone https://github.com/srsRAN/srsRAN.git && cd srsRAN && git checkout tags/release_19_12 && mkdir build && cd build && cmake ../ && make -j4 && sudo make install && sudo ldconfig && sudo ./srslte_install_configs.sh user
```

```
sudo nano /root/.config/srslte/enb.conf
```

```
[enb]
mcc = <yourMCC>
mnc = <yourMNC>
mme_addr = 127.0.1.100     ## or IP for external MME, eg. 192.168.1.10
gtp_bind_addr = 127.0.1.1  ## or local interface IP for external S1-U, eg. 192.168.1.3
s1c_bind_addr = 127.0.1.1  ## or local interface IP for external S1-MME, eg. 192.168.1.3
n_prb = 15
tm = 2
nof_ports = 2

[rf]
dl_earfcn = 1934
tx_gain = 80               ## this power seems to work best
rx_gain = 40
device_name = bladeRF
device_args = auto         ## does not work with anything other than 'auto'
```

```
sudo nano /root/.config/srslte/epc.conf
```

```
[mme]
mcc = <yourMCC>
mnc = <yourMNC>
mme_bind_addr = 127.0.1.100  ## or local interface IP for external S1-MME, eg. 192.168.1.10
```

srsRAN
======

srsRAN is a 4G/5G software radio suite developed by [SRS](http://www.srs.io).

See the [srsRAN project pages](https://www.srsran.com) for information, guides and project news.

The srsRAN suite includes:
  * srsUE - a full-stack SDR 4G/5G-NSA UE application (5G-SA coming soon)
  * srsENB - a full-stack SDR 4G/5G-NSA eNodeB application (5G-SA coming soon)
  * srsEPC - a light-weight 4G core network implementation with MME, HSS and S/P-GW

For application features, build instructions and user guides see the [srsRAN documentation](https://docs.srsran.com).

For license details, see LICENSE file.

Support
=======

Mailing list: https://lists.srsran.com/mailman/listinfo/srsran-users
