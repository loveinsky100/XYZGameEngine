//
//  Locker.h
//  XYZGameEngine
//
//  Created by Leo on 2016/11/28.
//  Copyright © 2016年 Leo. All rights reserved.
//

#ifndef Locker_h
#define Locker_h

#import <pthread.h>

namespace XYZGame
{
    struct Mutex
    {
        Mutex () : Mutex (false) {}
        
        ~Mutex ()
        {
            pthread_mutex_destroy (&_m);
        }
        
        Mutex (const Mutex&) = delete;
        Mutex &operator=(const Mutex&) = delete;
        
        void lock ()
        {
            pthread_mutex_lock(this->mutex());
        }
        
        void unlock ()
        {
            pthread_mutex_unlock (this->mutex());
        }
        
        pthread_mutex_t *mutex ()
        {
            return &_m;
        }
        
    protected:
        explicit Mutex (bool recursive)
        {
            if (!recursive)
            {
                pthread_mutex_init (&_m, NULL);
            }
            else
            {
                pthread_mutexattr_t attr;
                pthread_mutexattr_init (&attr);
                pthread_mutexattr_settype (&attr, PTHREAD_MUTEX_RECURSIVE);
                pthread_mutex_init (&_m, &attr);
                pthread_mutexattr_destroy (&attr);
            }
        }
        
    private:
        pthread_mutex_t _m;
    };
    
    struct Condition
    {
        Condition ()
        {
            pthread_cond_init(&_c, NULL);
        }
        
        ~Condition ()
        {
            pthread_cond_destroy(&_c);
        }
        
        // non-copyable.
        Condition(const Condition&) = delete;
        Condition &operator=(const Condition&) = delete;
        
        void signal()
        {
            pthread_cond_signal(&_c);
        }
        
        void wait(Mutex &m)
        {
            pthread_cond_wait(&_c, m.mutex());
        }
        
        pthread_cond_t *condition ()
        {
            return &_c;
        }
        
    private:
        pthread_cond_t _c;
    };
    
    class Locker
    {
        Mutex &_l;
    public:
        Locker(Mutex &l) : _l(l)
        {
            _l.lock ();
        }
        
        ~Locker ()
        {
            _l.unlock ();
        }
        
        Locker(const Locker &) = delete;
        Locker &operator=(const Locker &) = delete;
    };
    
    class Unlocker
    {
        Mutex &_l;
    public:
        Unlocker(Mutex &l) : _l(l)
        {
            _l.unlock ();
        }
        
        ~Unlocker()
        {
            _l.lock ();
        }
        
        Unlocker(Unlocker &) = delete;
        Unlocker &operator=(Unlocker &) = delete;
    };
}

#endif /* Locker_h */
