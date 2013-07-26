<?php
class Template {

	protected $variables = array();
	protected $_controller;
	protected $_action;
	private $_ignoreHeaders;

	function __construct($controller,$action) {
		$this->_controller = $controller;
		$this->_action = $action;
		$this->_ignoreHeaders = $GLOBALS['ignoreHeader'];
	}

	/** Set Variables **/

	function set($name,$value) {
		$this->variables[$name] = $value;
	}

	/** Display Template **/

    function render() {
		extract($this->variables);
		$viewDir = ROOT . DS . 'application' . DS . 'views';
			if(in_array($this->_action, $this->_ignoreHeaders)) // igores headers and footers is that value is set for the vurrent view 
			{
				include ($viewDir . DS . $this->_controller . DS . $this->_action . '.php');
				return;
			}
		
			include ($viewDir . DS . 'header.php');
			if (file_exists($viewDir . DS . $this->_controller . DS . $this->_action.'defineIncludes.php')) {
				include ($viewDir . DS . $this->_controller . DS . $this->_action.'defineIncludes.php');
			}
			include ($viewDir . DS . 'headerEnd.php'); // give views the chance to include there own stlysheets / js etc
			
			if (file_exists($viewDir . DS . $this->_controller . DS . 'header.php')) {
				include ($viewDir . DS . $this->_controller . DS . 'header.php');
			}
			
			include ($viewDir . DS . $this->_controller . DS . $this->_action . '.php');		 

			if (file_exists($viewDir . DS . $this->_controller . DS . 'footer.php')) {
				include ($viewDir . DS . $this->_controller . DS . 'footer.php');
			} 
			include ($viewDir . DS . 'footer.php');
    }

}
