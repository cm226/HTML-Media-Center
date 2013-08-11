<?php
class Template {

	protected $variables = array();
	protected $_controller;
	protected $_action;

	private $_ignoreHeaders;
	private $_viewVersion;	

	function __construct($controller,$action, $viewVersion) {
		$this->_controller = $controller;
		$this->_action = $action;
		$this->_ignoreHeaders = $GLOBALS['ignoreHeader1'];
		$this->_viewVersion = $viewVersion;
	}

	/** Set Variables **/

	function set($name,$value) {
		$this->variables[$name] = $value;
	}

	/** Display Template **/

    function render() {
		extract($this->variables);
		$viewDir = ROOT . DS . 'application' . DS . 'views';	

			if(in_array($this->_action, $this->_ignoreHeaders)) // igores headers and footers if that value is set for the current view 
			{
//				echo findFile( $this->_controller . DS . $this->_action . '.php');
				include ($this->findFile( $this->_controller . DS . $this->_action . '.php'));
				return;
			}
		
			include ($this->findFile('header.php'));
			if ($this->findFile($this->_controller . DS . $this->_action.'defineIncludes.php') != false) {
				include ($this->findFile( $this->_controller . DS . $this->_action.'defineIncludes.php'));
			}
			include ($this->findFile('headerEnd.php')); // give views the chance to include there own stlysheets / js etc
			
			if ($this->findFile($this->_controller . DS . 'header.php') != false) {
				include ($this->findFile($this->_controller . DS . 'header.php'));
			}
			
			include ($this->findFile($this->_controller . DS . $this->_action . '.php'));		 

			if ($this->findFile( $this->_controller . DS . 'footer.php')!=false) {
				include ($this->findFile($this->_controller . DS . 'footer.php'));
			} 
			include ($this->findFile('footer.php'));
    }


	/*
		This function shoud be removed after the refactor of joining the controllers and 
		Modle classes for the 2 sites has been done 

		It servs as a bridge to accomidate the half complete refactor
	*/
	function findFile($filename)
	{
		$viewDir = ROOT . DS . 'application' . DS . 'views';
		$newViewDir = ROOT . DS . 'application' . DS . 'views'. DS. $this->_viewVersion;

		if(file_exists($newViewDir . DS . $filename))
			return $newViewDir . DS . $filename;
		else if(file_exists($viewDir . DS . $filename))
			return $viewDir . DS . $filename;

		return false;			
	}

}
