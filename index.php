  
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
                        'text' => 'Здравствуйте, для данной игры нужно двое.
                        Я помогу вам в управлении вашей светодиодной шахматной доской, доступные команды:
                            помощь, 
                            что ты умеешь делать?
                            Перезагрузи игру.
                            Для выхода из навыка скажите хватит.',
                        'tts' => 'Здр+авствуйте, для д+анной игры нужно двое. Я помог+у вам в управл+ении в+ашей светоди+одной ш+ахматной доск+ой, дост+упные ком+анды: Помощь, что ты умеешь делать? Перезагрузи игру. Для выхода из навыка скажите хватит.',
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
	           	'е' => 'e',    'ё' => 'e',    'ж' => 'g',   'з' => 'z',    'джи' => 'g',
		        'й' => 'y',    'к' => 'k',    'л' => 'l',    'м' => 'm',    'н' => 'n',
	        	'о' => 'o',    'п' => 'p',    'р' => 'r',    'с' => 'c',    'т' => 't',
	           	'у' => 'u',    'ф' => 'f',    'х' => 'h',    'ц' => 'c',    'ч' => 'ch',
	        	'ш' => 'sh',   'щ' => 'sch',  'ь' => '',     'ы' => 'y',    'ъ' => '',
	        	'э' => 'e',    'ю' => 'yu',   'я' => 'ya','аш' => 'h', 'и'=>'','эйч' => 'h',
	        	'эйтч' => 'h','эйгхт' => 'h',    'бэ' => 'b',   'дэ' => 'd',   'эй' => 'a',
	        	'би' => 'b'
        	    );
        	
        	    $arduinostr = strtr($arduinostr, $converter);
        	    file_put_contents('data.txt', $arduinostr);
        	    $randInt =rand ( 0,5);
        	    if($randInt==0)$randomText ="хорошо";
        	    if($randInt==1)$randomText ="отлично";
        	    if($randInt==2)$randomText ="будет сделано";
        	    if($randInt==3)$randomText ="ок";
        	    if($randInt==4)$randomText ="слушаюсь";
        	    if($randInt==5)$randomText ="отличное начало";
        	
                 $response = json_encode([
                    'version' => '1.0',
                    'session' => [
                        'session_id' => $data['session']['session_id'],
                        'message_id' => $data['session']['message_id'],
                        'user_id' => $data['session']['user_id']
                    ],
                    'response' => [
                        'text' => $randomText,
                        'tts' => $randomText,
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
                    'command'=> $arduinostr
                ]);
            if($text == 'что ты умеешь делать')
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
                    'command'=> $arduinostr
                ]);
             if($text == 'что ты умеешь')
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
                if($text == 'пока')
                $response = json_encode([
                    'version' => '1.0',
                    'session' => [
                        'session_id' => $data['session']['session_id'],
                        'message_id' => $data['session']['message_id'],
                        'user_id' => $data['session']['user_id']
                    ],
                    'response' => [
                        'text' => 'Сыграем в следующий раз',
                        'tts' => 'Сыгр+аем в сл+едующий раз',
                        'buttons' => []
                    ],
                    'command'=> $arduinostr,
                    'end_session' => true
                ]);
            
            }
    }
  if($data['session']['session_id']==0){
     $response = json_encode([
                    'version' => '1.0',
                    'command'=> $arduinostr
                ]);
      echo $response;
  }
  else echo $response;
   
}
 catch(\Exception $e){
    echo '["Error occured"]';
} 
