# Insert Image into OLED Display Using Arduino

This guide provides step-by-step instructions for displaying an image on an OLED display (e.g., SSD1306) using an Arduino board.

## Requirements
- OLED Display (e.g., SSD1306 128x64 or 128x32)
- Arduino Board (e.g., Arduino Uno or Nano)
- OLED Libraries: `Adafruit_SSD1306` and `Adafruit_GFX`
- A tool to convert an image to a byte array (e.g., `LCD Assistant` or an online converter)

## Steps

### 1. Connect the OLED to Arduino
- **VCC** to **5V** (or 3.3V depending on your OLED)
- **GND** to **GND**
- **SCL** to **A5** (for I2C communication, depends on Arduino model)
- **SDA** to **A4** (for I2C communication, depends on Arduino model)

### 2. Install Libraries
- Open the Arduino IDE.
- Go to **Sketch > Include Library > Manage Libraries**.
- Search for and install the `Adafruit SSD1306` and `Adafruit GFX` libraries.

### 3. Convert Image to Byte Array
- Use an online tool or software like `LCD Assistant` to convert your image to a monochrome bitmap format (`.bmp`) that can be represented as a byte array.
- The recommended image size should match the resolution of your OLED (e.g., 128x64 pixels).
- Convert the image and copy the generated byte array.

### 4. Include Image Byte Array in Your Code
- In your Arduino sketch, paste the byte array. For example:
  ```cpp
  const unsigned char myImage[] PROGMEM = {
    // Paste the byte array here
  };

### 5. Initialize the OLED

- Set up the OLED using the `Adafruit_SSD1306` library.
  
### For more Detail refer to the Code ITSELF.
