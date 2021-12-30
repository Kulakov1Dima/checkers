<?php

function randomResponse($data){
    
    return json_encode([
                    'version' => '1.0',
                    'session' => [
                        'session_id' => $data['session']['session_id'],
                        'message_id' => $data['session']['message_id'],
                        'user_id' => $data['session']['user_id']
                    ],
                    'response' => [
                        'text' => $data['request']['command'],
                        'tts' => $data['request']['command'],
                        'buttons' => []
                    ],
                ]);
}


?>