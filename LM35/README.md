# گزارش کار پروژه : سنجش دما با استفاده از سنسور LM35

## قطعات و تجهیزات مورد استفاده

1.اردوینو 

2.سنسور دما (LM35)
 
3.مقاومت و LED

4. سیم جامپر
 
## شرح مدار
• پایه خروجی سنسور LM35 به پایه آنالوگ A0 برد Arduino متصل شده است .
• ال ای دی  به پایه دیجیتال شماره 9 از طریق مقاومت 330 اهم متصل شده است .
• پایههای VCC و GND به پایههای 5V و GND برد Arduino متصل شدهاند .


![](/LM35/lm35_schematic.jpg)

## شرح برنامه
کد نوشته شده شامل سه بخش اصلی است : 
1. تعریف پایهها و تنظیمات اولیه :
 - سنسور LM35 به پایه A0 متصل شده است . 
 - ال ای دی به پایه دیجیتال 9 متصل شده و به صورت خروجی تعریف شده است .
2. خواندن دادهها از سنسور LM35:
   - ولتاژ خروجی سنسور خوانده شده و به مقدار دما تبدیل میشود . از رابطه زیر برای تبدیل مقدار آنالوگ به دما استفاده شده است :
voltage=sensorValue*(5.0/1023.0); temperatureC=voltage*100;
3. کنترل LED بر اساس دما : - اگر دما بیشتر از 27 درجه سانتیگراد باشد، LED روشن میشود . - در غیر این صورت، LED خاموش میماند .
![lm35](https://github.com/user-attachments/assets/43be84c5-f3b1-4747-8fcc-6b41d27c5249)


## کد برنامه
```
const int lm35pin=A0;
int led=9;

void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);

}

void loop() {
  int sensorValue=analogRead(lm35pin);
  float voltage=sensorValue*(5.0/1023.0);
  float temperatureC=voltage*100;
  
  Serial.print("temperature:");
   Serial.print(temperatureC);
  Serial.println("*c");
  if(temperatureC>27){
    Serial.print("cooler on");
    digitalWrite(led,HIGH);
  }
  else{
     digitalWrite(led,LOW);
  
    
  }
  delay(1000);
}
```

## نتیجه گیری
این پروژه با موفقیت توانست دمای محیط را اندازهگیری کرده و در صورت افزایش دما از 27 درجه سانتیگراد، LED را روشن کند
