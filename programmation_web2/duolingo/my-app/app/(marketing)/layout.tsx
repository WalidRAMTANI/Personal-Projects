import React, { Children } from 'react'
import {Header} from './header';
import { Footer } from './footer';
type Props = {
    children: React.ReactNode
}

function Layoutpage({children}: Props) {
  return (

    <div className='min-h-screen flex flex-col'>
        <Header />
        <main className='flex-1 flex flex-col justify-center items-center'>
            {children}
        </main>
        <Footer/>
    </div>
    )
}

export default Layoutpage;