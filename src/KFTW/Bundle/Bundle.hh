<?hh

namespace KFTW\Bundle;

class Bundle {
    
    protected array<string, string> $routes;
    
    public function __construct() {
        $this->routes = [];
    }
    
    public function getRoutes() : array<string, string> {
        return $this->routes;
    }
    
    public function setRoutes(array<string, string> $routes) {
        $this->routes = $routes;
    }
}