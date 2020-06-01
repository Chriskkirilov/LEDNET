![](https://github.com/Kristiyan17/LED_Karh/blob/master/Capture.PNG?raw=true)

**LEDNET** е проект за хора, които искат да видят това, което чуват и да чуят това, което виждат.
Този проект ще покаже височината на тоновете и тяхната сила, например музика или вокали. Информацията за височината и силата на тоновете се изобразява върху лед матрица.

### Инструкции за инсталация
1) Инсталирайте си [Arduino IDE](https://www.arduino.cc/en/main/software), това е платформата, на която ще работите
2) Изтеглете файловете от репозиторито като натиснете `Clone or download`, след това натиснете `Download ZIP`. По този начин ще имате нужните файлове с код за проекта
3) Инсталирайте необходимите библиотеки [LEDControl](https://www.arduinolibraries.info/libraries/led-control) и [ArduinoFFT](https://www.arduinolibraries.info/libraries/arduino-fft). Форматът на библиотеките е *.zip*
4) След инсталацията на гореописаните файлове, отворете `led-net.ino` файла
5) За да използвате библиотеките във вашия проект, в Arduino IDE-то отидете към `Sketch->Include Library->Add .ZIP Library` и изберете двата *.zip* файла от директорията, в която сте ги изтеглили (обикновено е в Downloads)

### Инструкции за стартиране на проекта
1) Най-важното е да имате нужните части. Свържете ги по модела на [следната схема](https://github.com/Kristiyan17/LEDNET/blob/master/Schematic_equalizer_led_matrix_Sheet_1_20200122222708.png)
2) Първо верифицирайте кода, за да сте сигурни, че няма грешки. Това може да го направите като натиснете тикчето горе вляво
3) Свържете микроконтролерът към вашия омпютър с помощта на А към B кабела
4) Отидете към `Tools->Board` и изберете `Arduino/Genuino Uno`
5) Отидете към `Tools->Port` и изберете `COM3`
6) Качете кода във вашия микроконтролер, като го свържете с компютъра с помощта на А към B кабела

## Използвани технологии:

* [Arduino UNO микроконтролер](https://store.arduino.cc/arduino-uno-rev3) - *Този микроконтролер е сърцето на целия проект. С негова помощ всеки компонент има връзка с останалите и се пренася информация между тях.*

* [LED матрица](https://www.ardboard.com/LCD-TFT-%D0%B4%D0%B8%D1%81%D0%BF%D0%BB%D0%B5%D0%B9?product_id=163) - *LED матрицата е мястото, върху което ще се изобразява информацията(честотата и силата) на подадените сигнали. Тя е червена и е 32 на 8 ледчета*

* [Звуков сензор](http://www.elimex.bg/product/138916/kit-k2066-zvukov-senzor-v3.html)- *Звуковият сензор е важен компонент, който получава звуковите сигнали.*

* Jumpers- *малки проводници*

* A към B кабел

## [Презентация](https://docs.google.com/presentation/d/1Kl1TIclTjbiCRBxUy0PQNiOf59hQmvRr2rkTyPPAn90/edit#slide=id.g6df7031d0e_0_21)
## [Видео](https://www.youtube.com/watch?v=rVn4CTaqaKc)

## Снимки
![](https://github.com/Kristiyan17/LEDNET/blob/master/101604989_320160578973371_654539542597992448_n.jpg)
![](https://github.com/Kristiyan17/LEDNET/blob/master/101945629_706698926809774_1816225421893566464_n.jpg)


## Информация за автора на проекта
Кристиян Кирилов - *програмист, хардуерист* (от всичко по малко)
 - [Chris' GitHub](https://github.com/Kristiyan17)
 - [Chris' Facebook](https://www.facebook.com/ilovecinnamon123)
 - [Chris' LickedIn](https://www.linkedin.com/in/kristiyan-kirilov-b896261a8/)
