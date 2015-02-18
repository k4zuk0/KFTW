<?hh

namespace KFTW\Routing;

class Router {
    
    protected array<string, array<string>> $routes;
    
    public function __construct() {
        $this->routes = [];
    }
    
    public function setRoutes(array<string, array<string>> $routes) {
        $this->routes = $routes;
    }
    
    public function addRoutes(array<string, array<string>> $routes) {
        foreach ($routes as $k => $v) {
            $this->addRoute($k, $v);
        }
    }
    
    public function addRoute(string $routeName, array<string> $controllerInfos) {
        $this->routes[$routeName] = $controllerInfos;
    }
    
    public function getRoute(string $routeName) : ?array<string> {
        if (array_key_exists($routeName, $this->routes)) {
            return $this->routes[$routeName];
        }
        return null;
    }
    
    public function getRoutes() : array<string, array<string>> {
        return $this->routes;
    }
}