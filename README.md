# 🏎️ Retro Arcade Car Game

An infinite scrolling 2D arcade driving game built from scratch using **C++** and **Raylib**. All pixel art assets were custom-designed using **LibreSprite**.

---

## 🚀 Features Implemented So Far
* **Infinite Scrolling Track:** Implemented seamless vertical texture wrapping (`TEXTURE_WRAP_REPEAT`).
* **Custom Pixel Art:** Designed a 16x16 red sports car sprite and tiled road textures.
* **Arcade Handling:** Programmed responsive keyboard controls with simulated visual skid mark trails.
* **Collision Detection:** Formulated AABB boundary limits for left and right road shoulders with solid resolution handling.
* **Game Loop & State:** Programmed a central state engine supporting frozen Game Over overlays and live restarts (`R` key).

---

## 🛠️ Tech Stack & Tools
* **Language:** C++17
* **Framework:** Raylib
* **Art Assets:** LibreSprite (Portable Edition)

---

## 📸 Media / Screenshots
<img width="803" height="618" alt="image" src="https://github.com/user-attachments/assets/a8d72955-3c4b-483a-a537-d61b2c0de325" />
<img width="801" height="628" alt="image" src="https://github.com/user-attachments/assets/45a3e627-2697-4fb6-abec-0d76da293caa" />

---

## 📈 Learning Progress & Log
* **June 2026:** Initialized project window, loaded textures, and fixed basic loop function errors (`WindowShouldClose()`).
* **June 2026:** Solved texture scaling issues using `DrawTexturePro` vs `DrawTextureEx` and implemented road boundary hard-stopping physics.
