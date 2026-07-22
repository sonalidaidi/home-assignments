{
  "version": 1,
  "author": "Daidi sonali",
  "editor": "wokwi",
  "parts": [
    { "type": "board-esp32-devkit-c-v4", "id": "esp", "top": -28.8, "left": -33.56, "attrs": {} },
    { "type": "wokwi-relay-module", "id": "relay1", "top": -67, "left": 153.6, "attrs": {} },
    {
      "type": "wokwi-led",
      "id": "led1",
      "top": 82.8,
      "left": -236.2,
      "attrs": { "color": "white" }
    },
    {
      "type": "wokwi-led",
      "id": "led2",
      "top": 44.4,
      "left": -207.4,
      "attrs": { "color": "white" }
    },
    {
      "type": "wokwi-led",
      "id": "led3",
      "top": -3.6,
      "left": -178.6,
      "attrs": { "color": "white" }
    },
    {
      "type": "wokwi-pushbutton-6mm",
      "id": "btn1",
      "top": 67.7,
      "left": -130.9,
      "rotate": 90,
      "attrs": { "color": "green", "xray": "1" }
    },
    {
      "type": "wokwi-pushbutton-6mm",
      "id": "btn2",
      "top": 134.9,
      "left": -130.9,
      "rotate": 90,
      "attrs": { "color": "green", "xray": "1" }
    },
    {
      "type": "wokwi-pushbutton-6mm",
      "id": "btn3",
      "top": 10.1,
      "left": -130.9,
      "rotate": 90,
      "attrs": { "color": "green", "xray": "1" }
    },
    { "type": "wokwi-relay-module", "id": "relay2", "top": -9.4, "left": 153.6, "attrs": {} },
    { "type": "wokwi-relay-module", "id": "relay3", "top": 48.2, "left": 153.6, "attrs": {} }
  ],
  "connections": [
    [ "esp:TX", "$serialMonitor:RX", "", [] ],
    [ "esp:RX", "$serialMonitor:TX", "", [] ],
    [ "relay1:VCC", "esp:3V3", "red", [ "h-124.8", "h-57.75" ] ],
    [ "relay1:GND", "esp:GND.2", "black", [ "h-38.4", "v66.8" ] ],
    [ "relay1:IN", "esp:23", "green", [ "h-28.8", "v67" ] ],
    [ "relay2:VCC", "esp:3V3", "red", [ "h-48", "v-86.4", "h-134.55" ] ],
    [ "relay3:VCC", "esp:3V3", "red", [ "h-38.4", "v-134.4", "h-144.15" ] ],
    [ "relay2:GND", "esp:GND.2", "black", [ "h-48", "v9.2" ] ],
    [ "relay3:GND", "esp:GND.2", "black", [ "h-19.2", "v-48.4" ] ],
    [ "relay2:IN", "esp:22", "green", [ "h-86.4", "v-9.8" ] ],
    [ "relay3:IN", "esp:21", "green", [ "h-48", "v-0.2" ] ],
    [ "btn3:1.l", "esp:25", "green", [ "h19.2", "v28.8" ] ],
    [ "btn1:1.l", "esp:26", "green", [ "v0", "h76.8" ] ],
    [ "btn2:1.l", "esp:27", "green", [ "h19.2", "v-38.4" ] ],
    [ "esp:3V3", "relay1:COM", "green", [ "h-38.25", "v-86.4", "h355.2", "v49.4" ] ],
    [ "relay2:COM", "esp:3V3", "green", [ "h30", "v-126.2", "h-355.2", "v105.6" ] ],
    [ "relay3:COM", "esp:3V3", "green", [ "h39.6", "v-193.4", "h-355.2", "v-19.2" ] ],
    [ "relay1:NO", "led3:A", "green", [ "h58.8", "v-97.8", "h-460.8", "v172.8" ] ],
    [ "led2:A", "relay2:NO", "green", [ "v0", "h38.4", "v-220.8", "h480", "v163.2" ] ],
    [ "led1:A", "relay3:NO", "green", [ "v0", "h76.8", "v-268.8", "h480", "v230.4" ] ],
    [ "btn3:1.r", "esp:GND.1", "black", [ "v0.8", "h48", "v86.4" ] ],
    [ "btn1:1.r", "esp:GND.1", "black", [ "v0" ] ],
    [ "btn2:1.r", "esp:GND.1", "black", [ "v0.8", "h38.4", "v-38.4" ] ],
    [ "led3:C", "esp:GND.1", "black", [ "v134.4", "h106", "v-28.8" ] ],
    [ "led2:C", "esp:GND.1", "black", [ "v96", "h144.4", "v-67.2" ] ],
    [ "led1:C", "esp:GND.1", "black", [ "v67.2", "h144.4", "v-57.6" ] ]
  ],
  "dependencies": {}
}
