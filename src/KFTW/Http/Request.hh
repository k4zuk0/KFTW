<?hh

namespace KFTW\Http;

class Request {
    
    public function __construct(
        protected array $get = [],
        protected array $post = [],
        protected array $server = [],
        protected array $cookie = [],
        protected array $files = []
    ) {
        
    }
    
    public function get(?string $key = null) : mixed {
        if (isset($key)) {
            return (array_key_exists($key, $this->get)) ? $this->get[$key] : null;
        }
        return $this->get;
    }
    
    public function post(?string $key = null) : mixed {
        if (isset($key)) {
            return (array_key_exists($key, $this->post)) ? $this->post[$key] : null;
        }
        return $this->post;
    }
    
    public function server(?string $key = null) : mixed {
        if (isset($key)) {
            return (array_key_exists($key, $this->server)) ? $this->server[$key] : null;
        }
        return $this->server;
    }
    
    public function cookie(?string $key = null) : mixed {
        if (isset($key)) {
            return (array_key_exists($key, $this->cookie)) ? $this->cookie[$key] : null;
        }
        return $this->cookie;
    }
    
    public function files(?string $key = null) : mixed {
        if (isset($key)) {
            return (array_key_exists($key, $this->files)) ? $this->files[$key] : null;
        }
        return $this->files;
    }
}