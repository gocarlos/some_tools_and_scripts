# Run after boot: 

```shell
$ sudo nano .config/lxsession/LXDE-pi/autostart
$ @chromium-browser --kiosk --incognito https://www.srf.ch/play/tv/popupvideoplayer?id=c4927fcf-e1a0-0001-7edd-1ef01d441651
```

# Run with as a cronjob
```shell
$ sudo crontab -e 
$ 0 7 * * 1-5 export DISPLAY=:0 && chromium-browser --kiosk --incognito https://www.srf.ch/play/tv/popupvideoplayer?id=c4927fcf-e1a0-0001-7edd-1ef01d441651 && curl -sm 30 k.wdt.io/kmartinho8@gmail.com/wecker?c=0_7_*_*_1-5
```
