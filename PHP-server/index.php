<?php
include('RandomResponse.php');
include('phonemes.php');
include('configuration.php');
include('generationFixRequest.php');

header('Content-Type: application/json');

try{
    $arduinostr =file_get_contents("data.txt");
    $data = json_decode(file_get_contents('php://input'), true); 
    
    if (isset($data['request'], $data['request']['command'], $data['session'], $data['session']['session_id'], $data['session']['message_id'], $data['session']['user_id'])) {
            
            if($data['session']['message_id']!=0){
                
                $arduinostr = ArduinoPhonemes($data['request']['command']);
        	    file_put_contents('data.txt', $arduinostr);
        	    
        	    $response = randomResponse($data);
        	    if(configuration($arduinostr))$response=generationFixRequest(configuration($arduinostr));
            
            }
            else{
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
                ]);
            }
    }
echo $response;
   
}
 catch(\Exception $e){
    echo '["Error occured"]';
} 
