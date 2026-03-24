# ESP32 Firmware - Custom ST7789 160x128 Display Build

This is a customized build of Bruce firmware optimized for ESP32 with ST7789 160x128 TFT display and XPT2046 touch controller.

## Hardware Configuration

- **Display**: ST7789 160x128 TFT (SPI interface)
- **Touch**: XPT2046 resistive touch controller
  - MISO: GPIO 19
  - MOSI: GPIO 23
  - SCLK: GPIO 18
  - CS: GPIO 22
  - INT: GPIO 21
- **BADUSB**: RX=3, TX=1
- **Flash**: 8MB partition
- **PSRAM**: Enabled

## Build Optimizations

- **Excluded Modules**: nrf24, ir, gps, qr, wifi, ble, nfc (to reduce memory usage)
- **Optimization**: -Os (size optimization)
- **Memory Usage**:
  - iram0_2_seg: 2.87%
  - dram0_0_seg: 15.08%
  - drom0_0_seg: 1.35%

## How to Build

### Prerequisites
- PlatformIO
- Python 3.8+
- Git

### Build Commands
```bash
# Clone repository
git clone <your-github-repo-url>
cd firmware-main

# Build for custom ST7789 display
pio run -e custom-st7789-160x128

# Upload to ESP32
pio run -e custom-st7789-160x128 -t upload --upload-port COM5
```

### Manual Upload (if you have .bin file)
```bash
esptool.py --chip esp32 --port COM5 --baud 921600 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 40m --flash_size detect 0x10000 firmware.bin
```

## Configuration Files

- `boards/custom-st7789-160x128/custom-st7789-160x128.ini` - Board configuration
- `platformio.ini` - Main build configuration
- `boards/custom-st7789-160x128/` - Custom pin definitions

## Troubleshooting

### Windows Build Issues
If you encounter memory errors on Windows, try:
1. Build on Linux/WSL instead
2. Use Docker container
3. Exclude additional libraries in `platformio.ini`

### Memory Issues
The build is optimized for minimal memory usage. If you need additional features, you may need to:
- Use larger flash partitions
- Exclude more modules
- Use external PSRAM

## License

This project is based on Bruce firmware. See LICENSE file for details.
