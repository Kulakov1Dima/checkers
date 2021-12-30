<?php

function generationFixRequest($data){
    if($data == 3)
        $response = json_encode([
            'version' => '1.0',
            'session' => [
                'session_id' => $data['session']['session_id'],
                'message_id' => $data['session']['message_id'],
                'user_id' => $data['session']['user_id']
                ],
            'response' => [
                'text' => 'Работаю я просто:
                    Скажите начальную координату клетки, а затем конечную для выполнения хода.
                    Пример команд: 
                    Алиса, походи с клетки А3 на клетку Б4
                    Д6 на Е5
                    Убийство пешек совершается за несколько ходов',
                'tts' => 'Раб+отаю я пр+осто:
                    Скажите нач+альную координ+ату кл+етки, а зат+ем кон+ечную для выполн+ения х+ода.
                    Прим+ер ком+анд: 
                    Ал+иса, поход+и с кл+етки А3 на кл+етку Б4
                    Д6 на Е5
                    Уб+ийство п+ешек соверш+ается за н+есколько ход+ов',
                'buttons' => []
                ],
        ]);
    if($data == 1)
        $response = json_encode([
            'version' => '1.0',
            'session' => [
                'session_id' => $data['session']['session_id'],
                'message_id' => $data['session']['message_id'],
                'user_id' => $data['session']['user_id']
            ],
            'response' => [
                'text' => 'Я умею переставлять пешки на вашем устройстве "Светодиодная шахматная доска", сыграем? Для получения подробной информации скажите помощь',
                'tts' => 'Я умею переставлять пешки на вашем устройстве "Светодиодная шахматная доска", сыграем? Для получения подробной информации скажите помощь',
                        'buttons' => []
            ],
        ]);
    if($data == 2)
        $response = json_encode([
            'version' => '1.0',
            'session' => [
                'session_id' => $data['session']['session_id'],
                'message_id' => $data['session']['message_id'],
                'user_id' => $data['session']['user_id']
            ],
            'response' => [
                'text' => 'Я умею переставлять пешки на вашем устройстве "Светодиодная шахматная доска"',
                'tts' => 'Я умею переставлять пешки на вашем устройстве "Светодиодная шахматная доска"',
                'buttons' => []
            ],
        ]);
    if($data == 4)
        $response = json_encode([
            'version' => '1.0',
            'session' => [
                'session_id' => $data['session']['session_id'],
                'message_id' => $data['session']['message_id'],
                'user_id' => $data['session']['user_id']
            ],
            'response' => [
                'text' => 'Я - навык яндекс алисы для управления вашей шахматной доской, данный проект не стоит на месте - мне пришлось вмешаться',
                'tts' => 'Я - навык яндекс алисы для управления вашей шахматной доской, данный проект не стоит на месте - мне пришлось вмешаться',
                        'buttons' => []
            ],
        ]);
    return $response;
}

?>