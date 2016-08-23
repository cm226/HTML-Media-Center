<?php

class SQLQuery {
    protected $_dbHandle;
    protected $_result;

    /** Connects to database **/

    function connect($address, $account, $pwd, $name) {
        $this->_dbHandle = mysqli_connect($address, $account, $pwd,$name);
        if ($this->_dbHandle)
        {
                return 1;
        }
        else {
            return 0;
        }
    }

    /** Disconnects from database **/

    function disconnect() {
        if (@mysql_close($this->_dbHandle) != 0) {
            return 1;
        }  else {
            return 0;
        }
    }
    
    function selectAll() {
    	$query = 'select * from `'.$this->_table.'`';
    	return $this->query($query);
    }
    
    function select($id) {
    	$query = 'select * from `'.$this->_table.'` where `id` = \''.mysql_real_escape_string($id).'\'';
    	return $this->query($query, 1);    
    }

	
    /** Custom SQL Query **/

	function query($query, $singleResult = 0) {
		$this->_result = $this->_dbHandle->query($query);
		
		if (preg_match("/select/i",$query)) {
		$result = array();
		$tableField = array();
		$tempResults = array();
		$numOfFields = $this->_result->field_count;
		for ($i = 0; $i < $numOfFields; ++$i) {
		    array_push($tableField ,$this->_result->fetch_field_direct($i));
		}

		
			while ($row = $this->_result->fetch_row()) {
				
				for ($i = 0;$i < $numOfFields; ++$i) {
					$tempResults[$tableField[$i]->table][$tableField[$i]->name] = $row[$i];
				}
				if ($singleResult == 1) {
		 			$this->_result->free();
					return $tempResults;
				}
				array_push($result,$tempResults);
			}
			$this->_result->free();
			
			return($result);
		}
		

	}

    /** Get number of rows **/
    function getNumRows() {
        return $this->_result->num_rows;
    }

    /** Free resources allocated by a query **/

    function freeResult() {
        $this->_result->free();
    }

    /** Get error string **/

    function getError() {
        return $this->_dbHandle->error;
    }
}
