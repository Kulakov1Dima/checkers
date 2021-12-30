<?php

function configuration($request){
    $array = array(4 => 'racckag o cebe', 1 => 'chto ty umeesh delat', 2 => 'chto ty umeesh', 3 => 'pomosch');
    return array_search($request, $array);
}

?>