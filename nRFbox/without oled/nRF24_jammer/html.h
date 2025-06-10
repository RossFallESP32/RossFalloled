const char* html = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
            opacity: 0;
            animation: fadeIn 1s forwards;
        }

        @keyframes fadeIn {
            from {
                opacity: 0;
            }
            to {
                opacity: 1;
            }
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
            transform: translateY(20px);
            animation: slideIn 0.5s forwards;
        }

        @keyframes slideIn {
            from {
                transform: translateY(20px);
                opacity: 0;
            }
            to {
                transform: translateY(0);
                opacity: 1;
            }
        }

        .header {
            margin-bottom: 20px;
            animation: logoMovement 1s infinite alternate;
        }

        @keyframes logoMovement {
            0% { transform: translateY(0); }
            100% { transform: translateY(-5px); }
        }

        /* ปรับรูปโลโก้ใหม่ (ปรับขนาดให้ใกล้เคียงของเดิม) */
        .header img {
            width: 320px; 
            height: auto;
            margin-bottom: 10px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        /* เปลี่ยนสีตัวหนังสือในปุ่มจากสีขาวเป็นสีแดง */
        .button, .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: red;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover, .dropdown-button:hover {
            background-color: #0056b3; 
            transform: translateY(-4px) scale(1.05); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active, .dropdown-button:active {
            transform: translateY(2px); 
        }

        .button:focus, .dropdown-button:focus {
            outline: none; 
        }

        .settings-button {
            background-color: #28a745;
        }

        .ota-button {
            background-color: #ffc107; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.9);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown.show {
            display: flex;
            animation: dropdownExpand 0.6s forwards;
        }

        @keyframes dropdownExpand {
            0% {
                opacity: 0;
                transform: scaleY(0);
            }
        }

        .hidden {
            opacity: 0;
            transform: translateY(-20px);
            transition: opacity 0.2s ease, transform 0.2s ease;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.classList.toggle('show');

            const items = dropdown.querySelectorAll('.dropdown-button');

            if (dropdown.classList.contains('show')) {
                items.forEach((item, index) => {
                    setTimeout(() => {
                        item.classList.remove('hidden');
                        item.style.opacity = 1;
                        item.style.transform = 'translateY(0)';
                    }, index * 50);
                });
            } else {
                items.forEach((item) => {
                    item.classList.add('hidden');
                    item.style.opacity = 0;
                    item.style.transform = 'translateY(-20px)';
                });
            }
        }

        window.addEventListener('click', function(event) {
            const dropdown = document.getElementById('settingsDropdown');
            const settingsButton = document.querySelector('.settings-button');
            if (!settingsButton.contains(event.target) && !dropdown.contains(event.target)) {
                dropdown.classList.remove('show');
                const items = dropdown.querySelectorAll('.dropdown-button');
                items.forEach((item) => {
                    item.classList.add('hidden');
                    item.style.opacity = 0;
                    item.style.transform = 'translateY(-20px)';
                });
            }
        });
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <!-- เปลี่ยนรูปโลโก้เก่าออก แล้วใส่รูปใหม่ พร้อมปรับขนาดให้ใกล้เคียงของเดิม -->
            <img src="data:image/png;base64,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
sIO0aQAAAABJRU5ErkJggg==" alt="New Logo">
        </div>

        <div class="buttons">
            <button onclick="location.href='/bluetooth_jam'" class="button">Bluetooth jammer</button>
            <button onclick="location.href='/drone_jam'" class="button">Drone jammer</button>
            <button onclick="location.href='/wifi_select'" class="button">WiFi jammer</button>
            <button onclick="location.href='/ble_jam'" class="button">BLE jammer</button>
            <button onclick="location.href='/zigbee_jam'" class="button">Zigbee jammer</button>
            <button onclick="location.href='/misc_jammer'" class="button">Misc jammer</button>
            <button class="button settings-button" onclick="toggleDropdown()">Settings</button>
            <button onclick="location.href='/OTA'" class="button ota-button">OTA</button>
            <div id="settingsDropdown" class="dropdown">
                <button onclick="location.href='/setting_bluetooth_jam'" class="dropdown-button hidden">Bluetooth Jam</button>
                <button onclick="location.href='/setting_drone_jam'" class="dropdown-button hidden">Drone Jam</button>
                <button onclick="location.href='/setting_separate_together'" class="dropdown-button hidden">Separate or Together</button>
                <button onclick="location.href='/setting_misc_jam'" class="dropdown-button hidden">Misc Jam</button>
                <button onclick="location.href='/wifi_settings'" class="dropdown-button hidden">WiFi Settings</button>
            </div>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_ota = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
            transition: background-color 0.5s;
            opacity: 0;
            animation: fadeIn 1s forwards;
        }

        @keyframes fadeIn {
            from {
                opacity: 0;
            }
            to {
                opacity: 1;
            }
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 400px;
            position: relative;
            transform: translateY(20px);
            animation: slideIn 0.5s forwards;
        }

        @keyframes slideIn {
            from {
                transform: translateY(20px);
                opacity: 0;
            }
            to {
                transform: translateY(0);
                opacity: 1;
            }
        }

        h2 {
            margin-bottom: 20px;
        }

        .file-upload {
            position: relative;
            margin-top: 10px;
        }

        .file-upload input[type="file"] {
            display: none;
        }

        .file-upload label {
            display: inline-block;
            background-color: #007bff;
            color: white;
            padding: 10px 20px;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
        }

        .file-upload label:hover {
            background-color: #0056b3;
            transform: translateY(-4px) scale(1.05);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button {
            background-color: #28a745;
            border: none;
            color: white;
            padding: 10px 20px;
            text-align: center;
            text-decoration: none;
            display: inline-block;
            font-size: 16px;
            margin-top: 20px;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
        }

        .button:hover {
            background-color: #218838;
            transform: translateY(-4px) scale(1.05);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(2px);
        }

        .hint {
            margin-top: 10px;
            font-size: 14px;
            color: #cccccc;
        }

        .warning {
            margin-top: 15px;
            font-size: 14px;
            color: #ffcc00;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Firmware Update</h2>
        <form enctype='multipart/form-data' action='/update' method='POST'>
            <div class="file-upload">
                <label for="file-upload">Choose File</label>
                <input type='file' id="file-upload" name='update' accept=".bin" required>
            </div>
            <button class="button" type="submit">Upload</button>
            <div class="hint">Please select a .bin file for update.</div>
            <div class="warning">⚠️ Do not select bootloader or partition files!</div>
        </form>
    </div>
</body>
</html>
)rawliteral";

const char* html_upload_progress = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        #progress {
            width: 100%;
            background-color: #ddd;
            border-radius: 5px;
            overflow: hidden;
        }

        #progress-bar {
            width: 0;
            height: 30px;
            background-color: #007bff;
            text-align: center;
            color: white;
            transition: width 0.2s;
        }

        #status {
            margin-top: 10px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h2>Uploading Firmware...</h2>
        <div id="progress">
            <div id="progress-bar">0%</div>
        </div>
        <div id="status"></div>
    </div>
    <script>
        function updateProgress(percent) {
            const progressBar = document.getElementById("progress-bar");
            progressBar.style.width = percent + '%';
            progressBar.innerHTML = percent + '%';
        }
    </script>
</body>
</html>
)rawliteral";

const char* html_pls_reboot = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #007bff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #007bff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Please reboot</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '*&^%$#@!)(_+-';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_misc_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #007bff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #007bff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Jamming of selected channels</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '*&^%$#@!)(_+-';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_bluetooth_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #007bff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #007bff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Bluetooth Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '*&^%$#@!)(_+-';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_drone_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #007bff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #007bff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Drone Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '*&^%$#@!)(_+-';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_wifi_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #007bff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #007bff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">WiFi Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '*&^%$#@!)(_+-';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_ble_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #007bff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #007bff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">BLE Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '*&^%$#@!)(_+-';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_zigbee_jam = R"rawliteral(
<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
        }

        .text {
            font-size: 24px;
            color: #007bff;
            border-radius: 8px;
            margin-bottom: 15px;
            display: inline-block;
        }

        .circle-container {
            display: flex;
            justify-content: center;
            align-items: center;
        }

        .circle {
            width: 10px;
            height: 10px;
            margin: 0 5px;
            border-radius: 50%;
            background: linear-gradient(45deg, #007bff, #00c3ff);
            box-shadow: 0 0 10px rgba(0, 123, 255, 0.5),
                        0 0 20px rgba(0, 195, 255, 0.3);
            animation: pulse 1.2s infinite;
            transition: transform 0.2s ease-in-out;
        }

        .circle:nth-child(2) {
            animation-delay: 0.4s;
        }

        .circle:nth-child(3) {
            animation-delay: 0.8s;
        }

        @keyframes pulse {
            0%, 100% {
                transform: scale(1);
            }
            50% {
                transform: scale(1.5);
            }
        }
    </style>
</head>
<body>
    <div class="container">
        <div id="textElement" class="text">Zigbee Jamming</div>
        <div class="circle-container">
            <div class="circle"></div>
            <div class="circle"></div>
            <div class="circle"></div>
        </div>
    </div>

    <script>
        const textElement = document.getElementById('textElement');
        const originalText = textElement.textContent;
        const specialChars = '*&^%$#@!)(_+-';

        setInterval(() => {
            const words = originalText.split(' ');
            const randomWordIndex = Math.floor(Math.random() * words.length);
            const randomWord = words[randomWordIndex];

            if (randomWord) {
                const randomCharIndex = Math.floor(Math.random() * randomWord.length);

                const randomChar = specialChars[Math.floor(Math.random() * specialChars.length)];

                const modifiedWord = randomWord.split('');
                modifiedWord[randomCharIndex] = randomChar;
                words[randomWordIndex] = modifiedWord.join('');

                textElement.textContent = words.join(' ');

                setTimeout(() => {
                    modifiedWord[randomCharIndex] = randomWord[randomCharIndex];
                    words[randomWordIndex] = modifiedWord.join('');
                    textElement.textContent = words.join(' ');
                }, 999);
            }
        }, 1000);
    </script>
</body>
</html>
)rawliteral";

const char* html_bluetooth_setings = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #0056b3; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #0056b3;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Choose jamming type:</h1>
        </div>

        <div class="buttons">
            <button class="button" onclick="location.href='/bluetooth_method_0'">Brute Force By List (List 21)</button>
            <button class="button" onclick="location.href='/bluetooth_method_1'">Randomize Values (0-79)</button>
            <button class="button" onclick="location.href='/bluetooth_method_2'">Brute Force By Values (0-79)</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_drone_setings = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #0056b3; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #0056b3;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Choose jamming type:</h1>
        </div>

        <div class="buttons">
            <button class="button" onclick="location.href='/drone_method_0'">Randomize Values (0-125)</button>
            <button class="button" onclick="location.href='/drone_method_1'">Brute Force By Values (0-125)</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_misc_setings = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #0056b3; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #0056b3;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Choose jamming type:</h1>
        </div>
        <div class="buttons">
            <button class="button" onclick="location.href='/misc_method_0'">Channel Switching (fast mode; used in Bluetooth Jam)</button>
            <button class="button" onclick="location.href='/misc_method_1'">Packet Sending (slow mode; used in WiFi Jam)</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_separate_or_together = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #0056b3; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #0056b3;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Choose jamming type:</h1>
        </div>
        <div class="buttons">
            <button class="button" onclick="location.href='/separate_or_together_method_0'">Modules on Different Channels</button>
            <button class="button" onclick="location.href='/separate_or_together_method_1'">Modules on Same Channel</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_wifi_select = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .header {
            margin-bottom: 20px;
        }

        .buttons {
            display: flex;
            flex-direction: column;
            gap: 15px; 
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s; 
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #0056b3; 
            transform: translateY(-4px); 
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px); 
        }

        .button:focus {
            outline: none; 
        }

        .dropdown {
            position: absolute;
            top: 50px;
            right: 0;
            background-color: rgba(30, 30, 30, 0.8);
            border-radius: 8px;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            display: none;
            flex-direction: column;
            gap: 5px;
            z-index: 10;
        }

        .dropdown-button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            text-align: center;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .dropdown-button:hover {
            background-color: #0056b3;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .dropdown-button:active {
            transform: translateY(1px); 
        }

        .dropdown-button:focus {
            outline: none;
        }
    </style>
    <script>
        function toggleDropdown() {
            const dropdown = document.getElementById('settingsDropdown');
            dropdown.style.display = dropdown.style.display === 'flex' ? 'none' : 'flex';
        }
    </script>
</head>
<body>
    <div class="container">
        <div class="header">
            <h1>Select Jamming Type:</h1>
        </div>

        <div class="buttons">
            <button class="button" onclick="location.href='/wifi_jam'">Jam All Channels</button>
            <button class="button" onclick="location.href='/wifi_channel'">Select Channel To Jam</button>
        </div>
    </div>
</body>
</html>
)rawliteral";

const char* html_wifi_channel = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
            display: flex;
            flex-direction: column;
            align-items: center;
        }

        .input {
            background-color: #333333;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-size: 16px;
            width: 100%;
            margin-bottom: 15px;
            text-align: center;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
        }

        .input:focus {
            outline: none;
            background-color: #444444;
            box-shadow: 0 0 8px rgba(0, 123, 255, 0.5);
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #0056b3;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px);
        }

        .button:focus {
            outline: none;
        }
    </style>
    <script>
        function validateAndRedirect() {
            const channelValue = parseInt(document.getElementById('channelInput').value);

            if (isNaN(channelValue) || channelValue < 0 || channelValue > 12) {
                alert('Channel must be a number between 0 and 12.');
                return;
            }
            location.href = `/wifi_selected_jam?channel=${channelValue}`;
        }
    </script>
</head>
<body>
    <div class="container">
        <h1>Jam Channel:</h1>
        <input id="channelInput" class="input" type="number" placeholder="Channel (0-12)" max="12" min="0" />
        <button class="button" onclick="validateAndRedirect()">Submit</button>
    </div>
</body>
</html>
)rawliteral";

const char* html_wifi_settings = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
            opacity: 0;
            animation: fadeIn 1s forwards;
        }

        @keyframes fadeIn {
            from { opacity: 0; }
            to { opacity: 1; }
        }

        .container {
            display: flex;
            flex-direction: column;
            align-items: center;
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
            transform: translateY(20px);
            animation: slideIn 0.5s forwards;
        }

        @keyframes slideIn {
            from {
                transform: translateY(20px);
                opacity: 0;
            }
            to {
                transform: translateY(0);
                opacity: 1;
            }
        }

        .input {
            background-color: #333333;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-size: 16px;
            width: 100%;
            box-sizing: border-box;
            margin: 0 auto 15px;
            text-align: center;
            transition: background-color 0.3s, transform 0.2s;
        }

        .input:focus {
            outline: none;
            background-color: #444444;
            box-shadow: 0 0 8px rgba(0, 123, 255, 0.5);
        }

        label {
            display: block;
            margin-bottom: 8px;
            font-size: 14px;
            color: #aaaaaa;
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: calc(100% - 20px);
            box-sizing: border-box;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
            margin: 5px auto;
        }

        .button:hover {
            background-color: #0056b3;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px);
        }

        .button.reset {
            background-color: #dc3545;
        }

        .button.reset:hover {
            background-color: #c82333;
        }

        .warning {
            margin-top: 15px;
            font-size: 14px;
            color: #ffcc00;
            text-align: center;
            padding: 10px;
            border-radius: 5px;
            background-color: rgba(255, 204, 0, 0.1);
        }

        .notification {
            position: fixed;
            top: -100px;
            left: 50%;
            transform: translateX(-50%);
            padding: 15px 25px;
            border-radius: 0 0 8px 8px;
            color: white;
            font-weight: bold;
            z-index: 1000;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.2);
            transition: top 0.5s ease-out;
            width: 80%;
            max-width: 400px;
            text-align: center;
            opacity: 0;
            animation: notificationFadeIn 0.3s forwards;
        }

        @keyframes notificationFadeIn {
            from { opacity: 0; }
            to { opacity: 1; }
        }

        .success {
            background: linear-gradient(135deg, #28a745, #218838);
        }

        .error {
            background: linear-gradient(135deg, #dc3545, #c82333);
        }
    </style>
</head>
<body>
    <div id="notification" class="notification" style="display: none;"></div>

    <div class="container">
        <h1>WiFi Settings</h1>
        <form id="wifiForm">
            <input type="text" id="ssid" name="ssid" placeholder="Enter SSID" class="input">
            <input type="password" id="password" name="password" placeholder="Enter password" class="input">
            <button type="button" onclick="validateAndSave()" class="button">Save Settings</button>
            <button type="button" onclick="confirmReset()" class="button reset">Reset to Default</button>
        </form>
    </div>

    <script>
        function showNotification(message, isSuccess) {
            const notification = document.getElementById("notification");
            notification.textContent = message;
            notification.className = isSuccess ? "notification success" : "notification error";
            notification.style.display = "block";

            setTimeout(() => {
                notification.style.top = "20px";
            }, 10);

            setTimeout(() => {
                notification.style.top = "-100px";
                setTimeout(() => {
                    notification.style.display = "none";
                }, 500);
            }, 3000);
        }

        function validateAndSave() {
            const ssid = document.getElementById("ssid").value;
            const password = document.getElementById("password").value;

            if (ssid.length === 0 && password.length === 0) {
                showNotification("SSID must contain at least 1 character and password must be at least 8 characters", false);
                return;
            }

            if (ssid.length === 0) {
                showNotification("SSID must contain at least 1 character", false);
                return;
            }

            if (password.length === 0) {
                showNotification("Password must be at least 8 characters", false);
                return;
            }

            if (password.length < 8) {
                showNotification("Password must be at least 8 characters", false);
                return;
            }

            const formData = new FormData();
            formData.append("ssid", ssid);
            formData.append("password", password);

            showNotification("Saving settings...", true);

            fetch("/save_wifi_settings", {
                method: "POST",
                body: formData
            })
            .then(response => {
                if (response.ok) {
                    showNotification("Settings saved successfully! Rebooting...", true);
                    setTimeout(() => {
                        window.location.reload();
                    }, 2000);
                } else {
                    showNotification("Error saving settings", false);
                }
            })
            .catch(error => {
                console.error("Error:", error);
                showNotification("Connection error", false);
            });
        }

        function confirmReset() {
            if (confirm("Are you sure you want to reset to default settings?")) {
                showNotification("Resetting to default settings...", true);
                setTimeout(() => {
                    location.href = "/reset_wifi_settings";
                }, 1000);
            }
        }

        document.addEventListener('keypress', function(e) {
            if (e.key === 'Enter') {
                validateAndSave();
            }
        });
    </script>
</body>
</html>
)rawliteral";

const char* html_misc_jammer = R"rawliteral(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
        body {
            font-family: 'Arial', sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #121212;
            color: #ffffff;
        }

        .container {
            display: flex;
            flex-direction: column;
            align-items: center;
            text-align: center;
            padding: 30px;
            border-radius: 10px;
            background: #1e1e1e;
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.3);
            width: 90%;
            max-width: 350px;
            position: relative;
        }

        .input {
            background-color: #333333;
            color: #ffffff;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-size: 16px;
            width: 100%;
            margin-bottom: 15px;
            text-align: center;
            transition: background-color 0.3s, transform 0.2s;
        }

        .input:focus {
            outline: none;
            background-color: #444444;
            box-shadow: 0 0 8px rgba(0, 123, 255, 0.5);
        }

        .button {
            display: flex;
            justify-content: center;
            align-items: center;
            background-color: #007bff;
            color: white;
            border: none;
            border-radius: 8px;
            padding: 12px;
            font-weight: bold;
            cursor: pointer;
            transition: background-color 0.3s, transform 0.2s, box-shadow 0.2s;
            font-size: 16px;
            width: 100%;
            box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);
        }

        .button:hover {
            background-color: #0056b3;
            transform: translateY(-4px);
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.4);
        }

        .button:active {
            transform: translateY(1px);
        }

        .button:focus {
            outline: none;
        }
    </style>
    <script>
        function validateAndRedirect() {
            const startValue = parseInt(document.getElementById('startInput').value);
            const stopValue = parseInt(document.getElementById('stopInput').value);

            if (isNaN(startValue) || startValue < 0 || startValue > 125) {
                alert('Start value must be a number between 0 and 125.');
                return;
            }
            if (isNaN(stopValue) || stopValue < 0 || stopValue > 125) {
                alert('Stop value must be a number between 0 and 125.');
                return;
            }
            if (stopValue < startValue) {
                alert('Stop value must not be less than Start value.');
                return;
            }
            location.href = `/misc_jam?start=${startValue}&stop=${stopValue}`;
        }
    </script>
</head>
<body>
    <div class="container">
        <h1>Set Start/Stop Values:</h1>
        <input id="startInput" class="input" type="number" placeholder="Start (0-125)" max="125" min="0" />
        <input id="stopInput" class="input" type="number" placeholder="Stop (0-125)" max="125" min="0" />
        <button class="button" onclick="validateAndRedirect()">Jam</button>
    </div>
</body>
</html>
)rawliteral";

