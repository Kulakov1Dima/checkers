  
<?php

$dataRow = file_get_contents('php://input');
header('Content-Type: application/json');

$arduinostr =file_get_contents("data.txt");

$response = json_encode([
                    'version' => '1.0',
                    'session' => [
                        'session_id' => $data['session']['session_id'],
                        'message_id' => $data['session']['message_id'],
                        'user_id' => $data['session']['user_id']
                    ],
                    'response' => [
                        'text' => 'Я помогу вам в управлении светодиодной шахматной доской',
                        'tts' => 'Я помог+у вам в управл+ении светоди+одной ш+ахматной доск+ой',
                        'buttons' => []
                    ],
                    'command'=> $arduinostr
                ]);;

try{
    $data = json_decode($dataRow, true); 
    
    if (isset($data['request'], $data['request']['command'], $data['session'], $data['session']['session_id'], $data['session']['message_id'], $data['session']['user_id'])) {
        
            $text = $data['request']['command'];
            $id = $data['session']['message_id'];
            
            
            if($id!=0){
                
                $arduinostr = $text;
            
                $converter = array(
		        'а' => 'a',    'б' => 'b',    'в' => 'v',    'г' => 'g',    'д' => 'd',
	           	'е' => 'e',    'ё' => 'e',    'ж' => 'g',   'з' => 'z',    'и' => 'i',
		        'й' => 'y',    'к' => 'k',    'л' => 'l',    'м' => 'm',    'н' => 'n',
	        	'о' => 'o',    'п' => 'p',    'р' => 'r',    'с' => 's',    'т' => 't',
	           	'у' => 'u',    'ф' => 'f',    'х' => 'h',    'ц' => 'c',    'ч' => 'ch',
	        	'ш' => 'sh',   'щ' => 'sch',  'ь' => '',     'ы' => 'y',    'ъ' => '',
	        	'э' => 'e',    'ю' => 'yu',   'я' => 'ya'
        	    );
        	
        	    $arduinostr = strtr($arduinostr, $converter);
        	    file_put_contents('data.txt', $arduinostr);
        	
                 $response = json_encode([
                    'version' => '1.0',
                    'session' => [
                        'session_id' => $data['session']['session_id'],
                        'message_id' => $data['session']['message_id'],
                        'user_id' => $data['session']['user_id']
                    ],
                    'response' => [
                        'text' => 'хорошо',
                        'tts' => 'хорошо',
                        'buttons' => []
                    ],
                    'command'=> $arduinostr
                ]);
            if($text == 'помощь')
                $response = json_encode([
                    'version' => '1.0',
                    'session' => [
                        'session_id' => $data['session']['session_id'],
                        'message_id' => $data['session']['message_id'],
                        'user_id' => $data['session']['user_id']
                    ],
                    'response' => [
                        'text' => 'Скажите начальную координату клетки, а затем конечную для выполнения хода',
                        'tts' => 'Скаж+ите нач+альную координ+ату кл+етки, а зат+ем кон+ечную для выполн+ения х+ода',
                        'buttons' => []
                    ],
                    'command'=> $arduinostr
                ]);
                
            if($text == 'привет')
                $response = json_encode([
                    'version' => '1.0',
                    'session' => [
                        'session_id' => $data['session']['session_id'],
                        'message_id' => $data['session']['message_id'],
                        'user_id' => $data['session']['user_id']
                    ],
                    'response' => [
                        'text' => 'Привет, сыграем?',
                        'tts' => 'Прив+ет, сыграем?',
                        'buttons' => []
                    ],
                    'command'=> $arduinostr
                ]);
            if($text == 'расскажи о себе')
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
                    'command'=> $arduinostr
                ]);
                if($text == 'спасибо')
                $response = json_encode([
                    'version' => '1.0',
                    'session' => [
                        'session_id' => $data['session']['session_id'],
                        'message_id' => $data['session']['message_id'],
                        'user_id' => $data['session']['user_id']
                    ],
                    'response' => [
                        'text' => 'не за что',
                        'tts' => 'не за что',
                        'buttons' => []
                    ],
                    'command'=> $arduinostr
                ]);
            
            }
    }
   echo $response;
   
}
 catch(\Exception $e){
    echo '["Error occured"]';
} 